#include <iostream>

using namespace std;

void CountingSort(int *, int *, int);

const int k = 10000;

int main(){
  int n;
  cin >> n;

  int A[n];
  for(int i = 0; i < n; i++){
    cin >> A[i];
  }
  int B[n] = {0};


  CountingSort(A, B, n);

  for(int i = 0; i < n - 1; i++){
    cout << B[i] << " ";
  }
  cout << B[n - 1] << endl;
}

void CountingSort(int *A, int *B, int n){
  int C[k] = {0};

  for(int i = 0; i < n; i++){
    C[A[i]]++;
  }
  for(int i = 1; i < k; i++){
    C[i] += C[i - 1];
  }
  for(int i = n - 1; i >= 0; i--){
    B[C[A[i]] - 1] = A[i];
    C[A[i]]--;
  }
}

