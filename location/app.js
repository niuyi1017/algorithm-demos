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

app.get('/', (req, res) => {
  res.render('index', {
    title: 'location 首页'
  })
})

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


app.get('/locationlist', (req, res) => {
  res.render('locationlist', {
    title: 'location admin',
    user: {},
    location:{},
    users: [
      {
        lid: '1001001',
        meta: {
          updateAt: Date.now()
        },
        state: 0,
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
      },
      {
        lid: '1001006',
        meta: {
          updateAt: Date.now()
        },
        state: 1,
        _id: 32165465487
      },
      {
        lid: '1001007',
        meta: {
          updateAt: Date.now()
        },
        state: 1,
        _id: 32165465487
      }
    ]
  })
})

let locationDetail = { 
  addressComponent: {}
}

app.get('/detail', (req, res) =>{
  res.render('detail', {
    title: 'location 详情页',
    location: locationDetail
  })
})

app.get('/newuser', (req, res) => {
  res.render('newuser', {
    title: 'location new user',
    user: {}
  })
})
app.get('/newlocation', (req, res) => {
  res.render('newlocation', {
    title: 'location new location',
    user: {},
    location: {}
  })
})
app.get('/locateuser', (req, res) => {
  res.render('locateuser', {
    title: 'location new locateuser',
    user: {},
    location: {}
  })
})

app.post('/recLocation', (req, res) => {
  let locationData = req.body.dataStr
  res.send(locationData)
  locationDetail = JSON.parse(locationData)
  console.log(JSON.parse(locationData))
})

app.get('/getLocationData', (req, res) => {
  
  res.send(JSON.stringify(locationDetail))
  
})
console.log('node-mongodb started on port: ' + port)  