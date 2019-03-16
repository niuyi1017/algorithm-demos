const readLine = require('readline')
const rl = readLine.createInterface({
  input: process.stdin,
  output: process.stdout
})


let line = 0
let arr = []
rl.on('line', data => {
  line++
  arr = data.trim().split(' ')
  console.log(arr)
  if (line == 0) {
    process.exit(0)
  }
})