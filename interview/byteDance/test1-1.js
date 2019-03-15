const readline = require('readline')
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
})

let lineCount = 0  
let person = 0
let keys = []
let testNum = 0
let testArr = []

rl.on('line', data=>{
  lineCount++
  if(lineCount == 1){
    person = Number(data.trim())
  }else if(lineCount == 2){
    keys = data.trim().split(' ').map(x => Number(x))
  } else if (lineCount == 3){
    testNum = Number(data.trim())
  }else{
    testArr.push(data.trim().split(' ').map(x => Number(x)))
    testNum--
    if (testNum == 0){
      console.log(testArr)
      process.exit(0)
    }
  }
})