const User = require('../models/user')
const _ = require('underscore')

exports.login = (req, res) => {
  let _user = req.body.user
  let uid = _user.uid
  let password = _user.password

  User.findOne({ uid: uid }, (err, user) => {
    if (err) {
      console.log(err)
    }
    if (!user) {
      return res.redirect('/')
    }
    user.comparePassword(password, (err, isMatch) => {
      if (err) {
        console.log(err)
      }
      if (isMatch) {
        console.log("Password is matched!")
        req.session.user = user
        if(user.uid <= 1000){
          return res.redirect('/admin')
        }else{
          return res.redirect('/locationlist')
        }
      } else {
        console.log("Password is not matched!")
        return res.redirect('/')
      }
    })
  })
}

exports.logout =(req, res) => {
  delete req.session.user
  res.redirect('/')
}
exports.admin = (req, res) => {
  User.fetch((err, users) => {
    if (err) {
      console.log(err)
    }
    res.render('admin', {
      title: 'admin manager',
      users
    })
  })
}

exports.newUser = (req, res) => {
  res.render('newuser', {
    title: 'new user',
    user: {}
  })
}

exports.deleteUser = (req, res) => {
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
}
exports.updateUser = (req, res) => {
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
}
exports.saveUser = (req, res) => {
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
  } else {
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
}

//user signinREquired
exports.signinRequired = (req, res, next) => {
  let user = req.session.user
  if (!user) {
    return res.redirect('/')
  }
  next()
}

exports.adminRequired = (req, res, next) => {
  let user = req.session.user
  if (user.uid > 1000) {
    return res.redirect('/')
  }
  next()
}