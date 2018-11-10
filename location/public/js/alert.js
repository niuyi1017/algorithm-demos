var mask = $('#mask')
mask.hide(1)
$(function() {
  var mask = $('#mask')
  var alert = $('#alert')
  var button = $('#gps-btn')
  button.click(function(){
    mask.fadeIn(300)
  })
  alert.click(function () {
    mask.fadeOut(300)
  })
})