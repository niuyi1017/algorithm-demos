const readLine = require('readline')
const rl  = readLine.createInterface({
  input: process.stdin,
  output: process.stdout
})


let line = 0
let n = 0


rl.on('line', data => {
  line++
  let count = 0
  n = Number(data.trim())
  let total = 1024 - n
  
  if(total%64){
    count += Math.floor(total/64)
    total = total % 64
    if (total%16){
      count += Math.floor(total / 16)
      total = total % 16
    } if (total % 4) {
      count += Math.floor(total / 4) + total % 4
    }else {
      count += Math.floor(total / 4)
    }
  }

  console.log(count)
  if(line == 1){
    process.exit(0)
  }
})