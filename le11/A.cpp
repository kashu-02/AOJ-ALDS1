#include <iostream>
#include <vector>

using namespace std;

int main(){
  int n;
  cin >> n;

  vector<vector<int>> adj(n+1, vector<int>(n+1, 0));
  for(int i = 0; i < n; i++){
    int num, aaa;
    cin >> num >> aaa;
    for(int j = 0; j < aaa; j++){
      int num2;
      cin >> num2;
      adj[num][num2] = 1;
    }
  }

  for(int i = 1; i < n + 1; i ++){
    for(int j = 1; j < n; j++){
      cout << adj[i][j] << " ";
    }
    cout << adj[i][n] << endl;
  }
}