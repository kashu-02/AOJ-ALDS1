#include <stdio.h>

void insertionSort(int A[100], int N);

int main(){
  int N;
  int A[100], res[100];

  // Input array from standard input
  scanf("%d", &N);
  for(int i = 0; i < N; i++){
    scanf("%d", &A[i]);
  }

  // insertionSort
  insertionSort(A, N);

  for(int i = 0; i < N; i++){
    i != N - 1 ? printf("%d ", A[i]) : printf("%d", A[i]);
  }
  printf("\n");

  return 0;
}

void insertionSort(int A[100], int N){
  for(int i = 1; i < N; i++){
    for(int i = 0; i < N; i++){
      i != N - 1 ? printf("%d ", A[i]) : printf("%d", A[i]);
    }
    printf("\n");

    int v = A[i];
    int j = i - 1;
    while(j >= 0 && A[j] > v){
      A[j + 1] = A[j];
      j--;
    }
    A[j+1] = v;
  }
}
