#include <stdio.h>
#include <math.h>

int isPrime(int);

int prime_count = 0;

int main()
{
  int n, x;

  scanf("%d", &n);
  for(int i = 0; i < n; i ++){
    scanf("%d", &x);
    if(isPrime(x) == 1)
      prime_count++;
  }

  printf("%d\n", prime_count);

  return 0;
}

int isPrime(int x){
  if (x == 1 || x == 2)
    return 1;
  for(int i = 2; i <= sqrt(x); i++){
    if(x % i == 0)
      return 0;
  }
  return 1;
}