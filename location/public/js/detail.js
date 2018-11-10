$(function(){
  var map = new AMap.Map('location', {
    resizeEnable: true,
    zoom: 15,//级别
    center: [116.81965, 36.55545]
  })
  var marker = new AMap.Marker({
    position: new AMap.LngLat(116.81965000000002, 36.55545),   // 经纬度对象，也可以是经纬度构成的一维数组[116.39, 39.9]
  });
  map.add(marker);
  console.log('mark added')
  map.plugin(["AMap.ToolBar"], function () {
    var tool = new AMap.ToolBar();
    map.addControl(tool);
  });
})