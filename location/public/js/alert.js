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
//这两天光弄阿里云和linux了
// 明天开始写后端