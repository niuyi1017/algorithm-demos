var mask = $('#mask')
mask.hide()
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
//这两天光弄阿里云和linux了
// 明天开始写后端