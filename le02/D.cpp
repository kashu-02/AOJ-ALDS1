#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void insertionSort(int *A, int n, int g);
int cnt = 0;
int main()
{
  int n, m = 0;
  cin >> n;
  int A[n];
  vector<int> G;
  for(int i = 0; i < n; i++){
    cin >> A[i];
  }
  int aa = 0;
  for (m = 0;; m++)
  {
    aa = (pow(3,m) - 1) / 2;
    if(aa > n)
      break;
    if (aa != 0)
      G.push_back(aa);
  }
  m = G.size();

  for (int i = 0; i < m; i++){
    insertionSort(A, n, G[m - i - 1]);
  }
  cout << m << endl;
  for (int i = 0; i < m; i++){
    cout << G[m - i - 1] << " ";
  }
  if(m != 0){
    cout << endl;
  }

  cout << cnt << endl;

  for (int i = 0; i < n; i++)
  {
    cout << A[i] << endl;
  }
}

void insertionSort(int *A, int n, int g){
  for(int i = g; i < n; i++){
    int v = A[i];
    int j = i - g;
    while (j >= 0 && A[j] > v)
    {
      A[j + g] = A[j];
      j = j - g;
      cnt++;
    }
    A[j + g] = v;
  }
}
