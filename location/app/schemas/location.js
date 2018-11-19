const mongoose = require('mongoose')
const Schema = mongoose.Schema
const ObjectId = Schema.Types.ObjectId
const locationSchema = new mongoose.Schema({
  lid: {
    unique: true,
    type: String
  },
  user:{
    type: ObjectId,
    ref: 'User'
  },
  uid: String,
  state: {
    type: Number,
    default: 0  //0为定位中， 1为定位成功
  },
  locationMsg: String,
  meta: {
    createAt: {
      type: Date,
      default: Date.now()
    },
    updateAt: {
      type: Date,
      default: Date.now()
    }
  }
})

// 注意！！！schema中不可用 ES6箭头函数 ，否则 this = undefined
locationSchema.pre('save', function (next) {
  // let user = this
  if (this.isNew) {
    this.meta.createAt = this.meta.updateAt = Date.now()
  } else {
    this.meta.updateAt = Date.now()
  }
  next()
})

locationSchema.statics = {
  fetch: function (cb) {
    return this
      .find({})
      .sort('meta.updateAt')
      .exec(cb)
  },
  findById: function (id, cb) {
    return this
      .findOne({ _id: id })
      .exec(cb)
  }
}
module.exports = locationSchema