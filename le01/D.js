const line = require('fs').readFileSync('/dev/stdin', 'utf-8').split('\n');

let min = Number(line[1]);
let max = Math.pow(10,9) * -1;
line.forEach((value, index) => {
  value = Number(value);
  index = Number(index)
  if (index == 0) return;
  console.log(`index: ${index}, value:${value}`)
  console.log(line)
  if (value - min > max && index != 1) max = value - min;
  console.log(`max: ${max}`)
  if (value < min) min = value;
  console.log(`min: ${min}`);
})
console.log(max);
