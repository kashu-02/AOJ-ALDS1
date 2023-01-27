#include <iostream>

using namespace std;

int fib(int);

int mem[45] = { 1, 1};

int main(){
  int n;
  cin >> n;

  cout << fib(n) << endl;
}

int fib(int n){
  if(n == 0 || n == 1) return 1;
  if(mem[n] != 0){
    return mem[n];
  }else{
    mem[n] = (fib(n - 1) + fib(n - 2));
    return mem[n];
  }
}