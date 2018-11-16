const express = require('express')
const path = require('path')
const bodyParser = require('body-parser')
const mongoose = require('mongoose')

const cookieParser = require('cookie-parser')
const session = require('express-session')


const port = process.env.port || 3000
const app = express()

app.set('views', './views/pages')
app.set('view engine', 'pug')

app.use(bodyParser.json())
app.use(bodyParser.urlencoded({ extended: true }))

app.locals.moment = require('moment')
app.use(express.static(path.resolve(__dirname, 'public')))
app.listen(port)



//主页 
app.get('/', (req, res) => {
  res.render('index', {
    title: 'location 首页'
  })
})


// admin page == get userlist
app.get('/admin', (req, res) => {
  res.render('admin', {
    title: 'location admin',
    users: [
      {
        uid: '1000',
        mobile: '15953157925',
        password: '123456',
        notice: '无',
        meta: {
          updateAt: Date.now()
        },
        state: '正常',
        _id: 32165465487
      },
      {
        uid: '1001',
        mobile: '15953157925',
        password: '123456',
        notice: '无',
        meta: {
          updateAt: Date.now()
        },
        state: '正常',
        _id: 32165465487
      },
      {
        uid: '1002',
        mobile: '15953157925',
        password: '123456',
        notice: '无',
        meta: {
          updateAt: Date.now()
        },
        state: '正常',
        _id: 32165465487
      },
      {
        uid: '1003',
        mobile: '15953157925',
        password: '123456',
        notice: '无',
        meta: {
          updateAt: Date.now()
        },
        state: '正常',
        _id: 32165465487
      },
      {
        uid: '1004',
        mobile: '15953157925',
        password: '123456',
        notice: '无',
        meta: {
          updateAt: Date.now()
        },
        state: '正常',
        _id: 32165465487
      },
      {
        uid: '1005',
        mobile: '15953157925',
        password: '123456',
        notice: '无',
        meta: {
          updateAt: Date.now()
        },
        state: '正常',
        _id: 32165465487
      },
      {
        uid: '1006',
        mobile: '15953157925',
        password: '123456',
        notice: '无',
        meta: {
          updateAt: Date.now()
        },
        state: '正常',
        _id: 32165465487
      },
      {
        uid: '1007',
        mobile: '15953157925',
        password: '123456',
        notice: '无',
        meta: {
          updateAt: Date.now()
        },
        state: '正常',
        _id: 32165465487
      },
      {
        uid: '1008',
        mobile: '15953157925',
        password: '123456',
        notice: '无',
        meta: {
          updateAt: Date.now()
        },
        state: '正常',
        _id: 32165465487
      }
    ]
  })
})

// location list 

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


// user add
app.get('/newuser', (req, res) => {
  res.render('newuser', {
    title: 'location new user',
    user: {}
  })
})


// app.get('/newlocation', (req, res) => {
//   res.render('newlocation', {
//     title: 'location new location',
//     user: {},
//     location: {}
//   })
// })

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