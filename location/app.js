const express = require('express')
const path = require('path')
const bodyParser = require('body-parser')
const mongoose = require('mongoose')
const _ = require('underscore')

const cookieParser = require('cookie-parser')
const session = require('express-session')

const User = require('./models/user')
const port = process.env.port || 3000
const app = express()

const dbUrl = 'mongodb://localhost/location'
mongoose.connect(dbUrl, { useNewUrlParser: true })

app.set('views', './views/pages')
app.set('view engine', 'pug')

app.use(bodyParser.json())
app.use(bodyParser.urlencoded({ extended: true }))

app.locals.moment = require('moment')
app.use(express.static(path.resolve(__dirname, 'public')))
app.listen(port)


let locations = [
  {
    lid: '1001001',
    meta: {
      updateAt: Date.now()
    },
    state: 1, //0 = 定位中， 1 = 定位完成 
    _id: 32165465487
  },
  {
    lid: '1001002',
    meta: {
      updateAt: Date.now()
    },
    state: 1,
    _id: 32165465487
  },
  {
    lid: '1001003',
    meta: {
      updateAt: Date.now()
    },
    state: 1,
    _id: 32165465487
  },
  {
    lid: '1001004',
    meta: {
      updateAt: Date.now()
    },
    state: 1,
    _id: 32165465487
  },
  {
    lid: '1001005',
    meta: {
      updateAt: Date.now()
    },
    state: 1,
    _id: 32165465487
  }
]

//主页 
app.get('/', (req, res) => {
  res.render('index', {
    title: 'location 首页'
  })
})

// admin page == get userlist
app.get('/admin', (req, res) => {
  User.fetch((err, users) => {
    if (err) {
      console.log(err)
    }
    res.render('admin', {
      title: 'admin manager',
      users
    })
  })
})
// user add
app.get('/admin/newuser', (req, res) => {
  res.render('newuser', {
    title: 'new user',
    user: {}
  })
})

delete user
app.delete('/admin/del', (req, res) =>{
  let id = req.query.id
  if (id) {
    User.deleteOne({ _id: id }, (err, user) => {
      if (err) {
        console.log(err)
      }
      else {
        res.json({ success: 1 })
      }
    })
  }
})
//update user
app.get('/admin/updateuser/:id', (req, res) => {
  let id = req.params.id
  if (id) {
    User.findById(id, (err, user) => {
      if (err) {
        console.log(err)
      }
      res.render('newuser', {
        title: 'update user',
        user
      })
    })
  }
})
//new user form post
app.post('/admin/new', (req, res) => {
  let id = req.body.user._id
  let userObj = req.body.user
  let _user
  if (id) {
    User.findById(id, (err, user) => {
      if (err) {
        console.log(err)
      }
      _user = _.extend(user, userObj)
      _user.save((err, user) => {
        if (err) {
          console.log(err)
        }
        res.redirect('/admin')
      })
    })
  }else {
    _user = new User({
      uid: userObj.uid,
      password: userObj.password,
      state: userObj.state,
      notice: userObj.notice
    })
    _user.save((err, user) => {
      if (err) {
        console.log(err)
      }
      res.redirect('/admin')
    })
  }
})

// location list 
app.get('/locationlist', (req, res) => {
  res.render('locationlist', {
    title: 'location admin',
    // user: {},
    locations
  })
})

//ajax createLocationLog
app.post('/createLocationLog', (req, res) => {

  let lid = req.body.lid
  console.log(lid)
  let result
  let locatioinsLeng = locations.length
  let location = {
    lid,
    meta: {
      updateAt: Date.now()
    },
    state: 0,
    _id: 32165465487
  }
  locations.unshift(location)
  if (locations.length-locatioinsLeng == 1){
    result = {
      success: 1
    }
  }else{
    result = {
      err: 1
    }
  }
  res.send(result)
})


//location detail 
let locationDetail = { 
  addressComponent: {}
}

app.get('/detail/:lid', (req, res) =>{
  let locationDetail = {
    addressComponent: {}
  }
  let lid = req.params.lid
 
  for(let i = 0; i< locations.length; i ++){
    if (lid == locations[i].lid){
      locationDetail = locations[i].location
      console.log('locationDetail[i]: ')
      console.log(locationDetail)
    }
  }
  res.render('detail', {
    title: 'location 详情页',
    
    location: locationDetail
  })
})



//user located page on mobile
app.get('/locateuser', (req, res) => {
  res.render('locateuser', {
    title: 'location new locateuser',
    user: {},
    location: {}
  })
})
//ajax location data 
app.post('/recLocation', (req, res) => {
  let locationData = req.body.dataStr
  let lid = req.query.uid + req.query.lid
  console.log('post :'+lid)
  let result
  locationDetail = JSON.parse(locationData)
  console.log(JSON.parse(locationData))
  
  for(let i = 0; i<locations.length; i++){
    if(locations[i].lid == lid){
      locations[i].location = locationDetail
      locations[i].state = 1
      result = {
        success: 1
      }
      break;
    }
  }
  res.send(result)
})

//ajax get location data 
app.get('/getLocationData/:lid', (req, res) => {
  let lid = req.params.lid
  let locationDetail
  for(let i = 0; i<locations.length; i++){
    if (lid == locations[i].lid ){
      locationDetail = JSON.stringify(locations[i])
      res.send(locationDetail)
      break
    }
  }
})
console.log('node-mongodb started on port: ' + port)  