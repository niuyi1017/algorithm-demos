$(function(){
  var map = new AMap.Map('map', {
    resizeEnable: true
  })

  map.plugin('AMap.Geolocation', function () {
    var geolocation = new AMap.Geolocation({
      enableHighAccuracy: true,
      timeout: 10000,
      buttonOffset: new AMap.Pixel(10, 20),
      zoomToAccuracy: true,
      buttonPosition: 'RB'
    })
    geolocation.getCurrentPosition()
    AMap.event.addListener(geolocation, 'complete', onComplete)
    AMap.event.addListener(geolocation, 'error', onError)

    function onComplete(data) {
      var locationData = {
        addressComponent: {
          city: data.addressComponent.city,
          citycode: data.addressComponent.citycode,
          district: data.addressComponent.district,
          province: data.addressComponent.province,
          street: data.addressComponent.street + data.addressComponent.streetNumber,
          township: data.addressComponent.township 
        },
        formattedAddress: data.formattedAddress ,
        position: data.position
      }
      postData(locationData)
    }
    function onError(data) {
      console.log(data)
    }
  })
  function postData(data) {
    var search = window.location.search
    var dataStr = JSON.stringify(data)
    $.ajax({
      url: '/recLocation' + search,
      method: 'POST',
      dataType: 'jsonp',
      cache: true,
      crossDomain: true,
      data: {
        dataStr
      },
      dataType:'json',
      success: (data) => {
        console.log('success')
      }
    })
  }
})