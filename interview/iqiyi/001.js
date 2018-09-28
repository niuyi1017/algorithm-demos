function test(){
    var n = readInt();
    var arr  =new Array();
   
    var count = 0;
    for(var i = 1;i<=n;i++){
      
       if(i ==1){
           var temp = readInt();
           var obj = {
               max: temp,
               min: temp
           }
           arr.push(obj);
           count = 1;
       }else{

           arr.forEach(function (obj){
               if (temp >obj.max) {
                   obj.max = temp;
                   break;
               } else if (temp < obj.min) {
                  obj.min = temp;
                   break;
               } else {
                  arr.push({
                      max :temp,
                      min:temp
                  });
                  count ++;

               }
           });
       
       }
      
    }
    print(count);

}
test();