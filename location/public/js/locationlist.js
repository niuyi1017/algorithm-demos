$(function(){
  var genURL = $('#genURL')
  var Oloading = $('#Oloading')
  var OURL = $('#OURL')
  var refresh = $('#refresh')
  var url = $('#url')
  var baseUrl = 'http://localhost:3000/locateuser?lid=' 

  refresh.click(function(){
    window.location.reload()
  })
  genURL.click(function(){
    OURL.slideUp(300)
    var lid = $('#inputLid').val()
    if(lid){
      genURL.html('URL生成中，请稍后...')
      genURL.attr("disabled", true)
      Oloading.slideDown(300)

      var uid = $('#inputUid').val()
      var urlValue = baseUrl+ lid + '&uid='+ uid 
      
      $.post({
        url: '/createLocationLog',
        data: {lid: uid+lid},
        dataType: 'json',
        success: function(data){
          if(data.success){
            url.val(urlValue)
            setTimeout(() => {
              Oloading.slideUp(500)
              OURL.slideDown(500)
              genURL.removeClass('btn-outline-secondary')
                .addClass('btn-info')
                .html('专属定位链接生成完毕！')
                .attr("disabled", true)
            }, 2000)
          }else{
            setTimeout(() => {
              Oloading.slideUp(500)
              genURL.removeClass('btn-outline-secondary')
                .addClass('btn-info')
                .html('定位链接生成出错：' + data.err)
                .attr("disabled", true)
            }, 10000)
          }
        }
      })
    }else {
      alert("请先填写定位标识")
      genURL.html('一键生成专属定位链接')
    }
  })
  $('#newlocationModal').on('hidden.bs.modal', function (e) {
    OURL.fadeOut(500)
    genURL.html('一键生成专属定位链接')
          .addClass('btn-outline-secondary')
          .removeClass('btn-info')
          .attr('disabled',false)
    var lid = $('#inputLid').val("")
  })
})