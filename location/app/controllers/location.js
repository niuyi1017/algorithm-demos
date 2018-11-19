const Location = require('../models/location')
// const _ = require('underscore')

exports.createLocationLog = (req, res) => {
  let user = req.session.user._id
  console.log('createLoctionLog user')
  console.log(user)
  let lid = req.body.lid
  console.log(lid)
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
    title: 'location new locateuser',
    user: {},
    location: {}
  })
}

exports.recLocation = (req, res) => {
  let locationData = req.body.dataStr
  let lid = req.query.uid + req.query.lid
  console.log('post :' + lid)
  let result
  // locationDetail = locationData
  console.log("locationData before update")
  console.log(locationData)
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
        console.log("locationData after update")
        console.log(locationData)
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
      title: "location detail lid: " + location.lid,
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
    console.log("locationMsg :")
    console.log(locationMsg )

    let positioin = locationMsg.position
    console.log("position " + positioin)
    res.send(positioin)
  })

}

  