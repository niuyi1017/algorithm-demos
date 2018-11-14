$(function(){
  var mapOptions = {
    resizeEnable: true,
    zoom: 15,//级别
  }

  $.ajax({
    method:"GET",
    url:'/getLocationData',
    dataType:'json',
    success: function(data){
      console.log(data)
      mapOptions.center = [data.position.lng, data.position.lat]
      var map = new AMap.Map('location', mapOptions)
      var p = data.position.P
      var o = data.position.O
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