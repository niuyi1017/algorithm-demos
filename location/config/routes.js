const Index = require('../app/controllers/index')
const User = require('../app/controllers/user')
const Location = require('../app/controllers/location')

module.exports = (app) => {
  //pre handle user
  app.use((req, res, next) => {
    let _user = req.session.user
    app.locals.user = _user
    next()
  })

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
  app.get('/user/locationlist', User.signinRequired, User.locationList)


  //location 

  //ajax createLocationLog
  app.post('/createLocationLog', User.signinRequired, Location.createLocationLog)
 //detail page
  app.get('/detail/:id', User.signinRequired, Location.detail)
  //user located page on mobile
  app.get('/locateuser', Location.locateUser)
  //ajax location data 
  app.post('/recLocation', Location.recLocation)
  //ajax get location data for map
  app.get('/getLocationData/:id',  User.signinRequired,Location.getLocationData)
}
