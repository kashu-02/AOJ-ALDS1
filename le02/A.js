const line = require('fs').readFileSync('/dev/stdin', 'utf-8').split('\n')[1].split(" ").map((value) => {return Number(value)});

let flag = 1;
let changed_time = 0;

while(flag){
  flag = 0;
  for(let j = line.length - 1; j >= 1; j--){
    if(line[j] < line[j - 1]){
      [line[j - 1], line[j]] = [line[j], line[j - 1]];
      changed_time++;
      flag = 1;
    }
  }
}

const result = line.join(" ");
console.log(result);
console.log(changed_time);


