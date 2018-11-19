$(function(){
  var mapOptions = {
    resizeEnable: true,
    zoom: 15,//级别
  }

  var pathname = window.location.pathname
  var id = pathname.split('/')[2]

  $.ajax({
    method:"GET",
    url:'/getLocationData/' + id,
    dataType:'json',
    success: function(data){
      console.log(data)
      mapOptions.center = [data.lng, data.lat]
      var map = new AMap.Map('location', mapOptions)
      var p = data.P
      var o = data.O
      console.log(p)
      var marker = new AMap.Marker({
        position: new AMap.LngLat(p, o),   // 经纬度对象，也可以是经纬度构成的一维数组[116.39, 39.9]
      });
      map.add(marker);
      console.log('mark added')
      map.plugin(["AMap.ToolBar"], function () {
        var tool = new AMap.ToolBar();
        map.addControl(tool);
      })

    }

  })
})