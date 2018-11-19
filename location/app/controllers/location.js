const Location = require('../models/location')
exports.createLocationLog = (req, res) => {
  let user = req.session.user._id
  let lid = req.body.lid
  let result
  let _location = new Location({
    lid,
    user,
    state: 0,
  })
  _location.save((err, location) => {
    if (err) {
      console.log(err)
      result = {
        err: 1
      }
    }
    result = {
      success: 1
    }
    res.send(result)
  })
 
}

exports.locateUser = (req, res) => {
  res.render('locateuser', {
    title: '定位查询系统',
    user: {},
    location: {}
  })
}

exports.recLocation = (req, res) => {
  let locationData = req.body.dataStr
  let lid = req.query.uid + req.query.lid
  let result
  Location.updateOne({lid: lid},{
      $set: { 
        locationMsg: locationData,
        state: 1
      }
    }, (err,location) => {
      if(err){
        console.log(err)
        result = {
          err: 1
        }
      }else{
        result = {
          success: 1
        }
      }
      res.send(result)
  })
 
}

exports.detail = (req, res) => {
  let id = req.params.id
  Location.findById(id, (err, location) => {
    if (err){
      console.log(err)
    }
    let jsonLocation = JSON.parse(location.locationMsg)
    res.render('detail', {
      title: "位置详情  lid:" + location.lid,
      location: jsonLocation
    })
  })
}
exports.getLocationData = (req, res) => {
  let id = req.params.id
  Location.findById(id, (err, location) => {
    if (err) {
      console.log(err)
    }
    let locationMsg = JSON.parse(location.locationMsg)
    let positioin = locationMsg.position
    res.send(positioin)
  })

}

  