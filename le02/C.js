const line = require('fs').readFileSync('/dev/stdin', 'utf-8').split('\n')[1].split(" ");

const BubbleSort = (C) =>{
  for(let i = 0; i < C.length; i++){
    for(let j = C.length - 1; j >= i + 1; j--){
      if(C[j][1] < C[j-1][1]){
        [C[j - 1], C[j]] = [C[j], C[j - 1]]; //swap
      }
    }
  }

  return C;
}

const SelectionSort = (C) =>{
  for(let i = 0; i < C.length; i++){
    let minj = i;
    let j;
    for(j = i; j < C.length; j++){
      if(C[j][1] < C[minj][1]) minj = j;
    }
    if (minj != i) {
      const tmp = C[minj];
      C[minj] = C[i];
      C[i] = tmp;
    }
  }

  return C
}

  

const nline = line.map((value) =>{
  return [value.charAt(0), Number(value.charAt(1))]
});

const isStable = (check, bubble_sorted) => {
  return check.every((value, index) => {
    return value == bubble_sorted[index]
  })
}

const bubble_sorted = BubbleSort(nline.slice());
console.log(bubble_sorted.map((value) => {
  return value.join("")
}).join(" "));
console.log("Stable");

const selection_sorted = SelectionSort(nline.slice());
console.log(selection_sorted.map((value) => {
  return value.join("")
}).join(" "));
console.log(isStable(selection_sorted.slice(), bubble_sorted.slice()) ? "Stable" : "Not stable");

