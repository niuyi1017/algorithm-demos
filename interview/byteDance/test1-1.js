const readline = require('readline')
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
})

let lineCount = 0  
let person = 0
let keys = []
let testNum = 0
let sameKeys = {}

rl.on('line', data=>{
  lineCount++
  if(lineCount == 1){
    person = Number(data.trim())
  }else if(lineCount == 2){
    keys = data.trim().split(' ').forEach((value,index) => {
      if(sameKeys[value]){
        sameKeys[value].push(++index)
      }else{
        sameKeys[value] = [++index]
      }
    });
  } else if (lineCount == 3){
    testNum = Number(data.trim())
  }else{
    testNum--
    let [start, end, k] = data.trim().split(' ')
    start = parseInt(start)
    end = parseInt(end)
    let count = 0
    if (sameKeys[k]){
      sameKeys[k].forEach(item => {
        if(item<=end &&item >=start)
        count++
      })
    }
    console.log(count)
    if (testNum == 0){
      process.exit(0)
    }
  }
})