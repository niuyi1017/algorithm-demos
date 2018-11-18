const Index = require('../app/controllers/index')
const User = require('../app/controllers/user')


module.exports = (app) => {
  //pre handle user
  app.use((req, res, next) => {
    let _user = req.session.user
    app.locals.user = _user
    next()
  })

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

  //index
  app.get('/', Index.index)
  //login
  app.post('/login', User.login)
  //logout
  app.get('/logout', User.logout)
  // admin page == get userlist
  app.get('/admin', User.signinRequired, User.adminRequired, User.admin)
  // user add
  app.get('/admin/newuser', User.signinRequired, User.adminRequired,  User.newUser)
  //delete user
  app.delete('/admin/del', User.signinRequired, User.adminRequired,  User.deleteUser)
  //update user
  app.get('/admin/updateuser/:id', User.signinRequired, User.adminRequired,  User.updateUser)
  //new user form post
  app.post('/admin/saveuser', User.signinRequired, User.adminRequired,  User.saveUser)
  

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
    if (locations.length - locatioinsLeng == 1) {
      result = {
        success: 1
      }
    } else {
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

  app.get('/detail/:lid', (req, res) => {
    let locationDetail = {
      addressComponent: {}
    }
    let lid = req.params.lid

    for (let i = 0; i < locations.length; i++) {
      if (lid == locations[i].lid) {
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
    console.log('post :' + lid)
    let result
    locationDetail = JSON.parse(locationData)
    console.log(JSON.parse(locationData))

    for (let i = 0; i < locations.length; i++) {
      if (locations[i].lid == lid) {
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
    for (let i = 0; i < locations.length; i++) {
      if (lid == locations[i].lid) {
        locationDetail = JSON.stringify(locations[i])
        res.send(locationDetail)
        break
      }
    }
  })




}
