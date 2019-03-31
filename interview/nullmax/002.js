const readLine = require('readline')
const rl = readLine.createInterface({
  input: process.stdin,
  output: process.stdout
})


let inputs = []
let N = 0
rl.on('line', data => {
  if (N == 0) {
    N = Number(data.trim())
  } else {
    inputs.push(data.trim())
    if (N == inputs.length) {
      handle(inputs)
      process.exit(0)
    }
  }
})
function handle(inputs) {
  inputs.sort()
  for(let i = 0; i<inputs.length;i++){
    console.log(inputs[i])
  }
}