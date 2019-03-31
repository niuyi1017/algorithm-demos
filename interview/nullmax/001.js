const readLine = require('readline')
const rl = readLine.createInterface({
  input: process.stdin,
  output: process.stdout
})


let inputs = []
let N = 0
rl.on('line', data => {
  if(N == 0){
    N = Number(data.trim())
  }else{
    inputs.push(data.trim())
    if(N == inputs.length){
      handle(inputs)
      process.exit(0)
    }
  }
})
function handle(inputs) {
  inputs.forEach(item => {
    let result = []
    for(let i = 1;i<=item;i++){
      result.push(i)
    }
    let ret = []
    while(result.length>2){
      ret.push(result.shift())
      result.push(result[0])
      result.shift()
      // console.log(result)
    }
    for(let i = 0;i<result.length;i++){
      ret.push(result[i])
    }
    console.log(ret.join(" "))
  })
}