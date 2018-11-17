$(function () {
  $('.del').click(function (e) {
    console.log(e.target)
    let target = $(e.target)
    let id = target.data('id')
    let tr = $('.item-id-' + id)


    $.ajax({
      method: 'DELETE',
      url: '/admin/?id=' + id,
    })
      .done(results => {
        if (results.success == 1) {
          if (tr.length > 0) {
            tr.hide(300, function(){
              tr.remove()
            })
          }
        }
      })
  })
})