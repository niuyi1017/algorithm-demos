var mask = $('#mask')
mask.hide()
$(function() {
  var mask = $('#mask')
  var alert = $('#alert')
  var button = $('#gps-btn')
  button.click(function(){
    mask.fadeIn(300, () => {
      alert.fadeIn(300)
    })
  })
  alert.click(function () {
    alert.fadeOut(300, () =>{
      mask.fadeOut(300)
    })
  })
})