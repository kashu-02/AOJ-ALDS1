#include <stdio.h>

int main(){
  int N, tmp, changed_time = 0;
  scanf("%d", &N);
  int A[N];
  for(int i = 0; i < N; i++){
    scanf("%d", &A[i]);
  }

  for(int i = 0; i < N; i++){
    int minj = i;
    for(int j = i; j < N; j++){
      if(A[j] < A[minj]){
        minj = j;
      }
    }
    if(minj != i){
      tmp = A[i];
      A[i] = A[minj];
      A[minj] = tmp;
      changed_time++;
    }
  }

  for(int i = 0; i < N - 1; i++){
    printf("%d ", A[i]);
  }
  printf("%d\n", A[N-1]);
  printf("%d\n", changed_time);
}