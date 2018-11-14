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

      console.log('data: ')
      console.log(data)
      console.log('locationData: ')
      console.log(locationData)
      postData(locationData)
     
    }
    function onError(data) {
      // 定位出错
      // locationData = data
      console.log(data)
      
    }
  })
  function postData(data) {
    var dataStr = JSON.stringify(data)
    console.log(dataStr)
    $.ajax({
      url: '/recLocation',
      method: 'POST',
      dataType: 'jsonp',
      cache: true,
      crossDomain: true,
      data: {
        dataStr
      },
      dataType:'json',
      success: (data) => {
        console.log('success' + data)

      }
    })
    console.log('ajax' + data)
  }
})