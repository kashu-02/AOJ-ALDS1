#include <iostream>

using namespace std;

int partition(int *, int, int);


int main(){
  int n;
  cin >> n;
  int A[n];

  for(int i = 0; i < n;i++){
    cin >> A[i];
  }

  int q = partition(A, 0, n - 1);
  for (int i = 0; i < n - 1; i++)
  {
    if(i == q){
      cout << "[" << A[i] << "]" << " ";
    }else{
      cout << A[i] << " ";
    }
  }
  if(n == q){
    cout << "[" << A[n - 1] << "]" << endl;
  }else{
    cout << A[n - 1] << endl;
  }

  return 0;
}

int partition(int *A, int p, int r){
  int x = A[r];
  int i = p - 1;
  for(int j = p; j < r; j++){
    if(A[j] <= x){
      i++;
      swap(A[i], A[j]);
    }
  }
  swap(A[i + 1], A[r]);
  return i + 1;
}