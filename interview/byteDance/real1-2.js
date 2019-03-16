const readLine = require('readline')
const rl = readLine.createInterface({
  input: process.stdin,
  output: process.stdout
})

let line = 0
let testNum = 0 
let test = ''

rl.on('line', data => {
  line ++ 
  if(line == 1)
    testNum = Number(data.trim())
  else{
    test = data.trim().split('')
    handle(test)
    if (line == (testNum+1)){
      process.exit(0)
    }
  }
  
})
function handle(test) {
  let result = []
  
  for (let index = 0; index < test.length; index++) {
    const item = test[index];
    if(index < 2){
      result.push(item)
    }else{
      if (item == result[result.length-1]){
        if (item == result[result.length - 2]){
          continue
        }else{
          if(result.length<2){
            result.push(item)
          }else{
            if (result[result.length - 2] == result[result.length - 3]){
              continue
            }else{
              result.push(item)
            }
          }
        }
      }else{
        result.push(item)
      }
    } 
  }
  console.log(result.join(''))
}
