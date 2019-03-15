const readline = require('readline')
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
})

let lineCount = 0
let person = 0 //人数
let keys = [] //喜好值s
let testNum = 0 // 组数
let testArr = [] //二维数组，各个组及组内值

rl.on('line', data => {
  lineCount++
  if(lineCount == 1){
    person = Number(data.trim())
  } else if (lineCount == 2){
    keys=data.trim().split(' ').map(x=>Number(x))
  } else if (lineCount == 3){
    testNum = Number(data.trim())
  }else{
    testArr.push(data.trim().split(' ').map(x => Number(x)))
    testNum--
    if (testNum==0 ){
      console.log(person)
      console.log(keys)
      console.log(testNum)
      console.log(testArr)
      keys.length = 0
      testArr.length = 0
      process.exit(0);
  }
}
})