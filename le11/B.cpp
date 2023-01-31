#include <iostream>
#include <vector>

using namespace std;

void dfs(const vector<vector<int>> &, int, vector<vector<int>> &);

int cnt = 1;

int main(){
  int n;
  cin >> n;
  vector<vector<int>> G(n + 1, vector<int>());
  vector<vector<int>> seen(n + 1, vector<int>(2, 0));

  for (int i = 1; i < n + 1; i++){
    int index, num;
    cin >> index >> num;
    for (int j = 1; j < num + 1; j++){
      int index2;
      cin >> index2;
      G[index].push_back(index2);
    }
  }
  
  for (int i = 1; i < n + 1; i++){
    if(seen[i][0] == 0){
      dfs(G, i, seen);
    }
  }

  for (int i = 1; i < n + 1; i++){
    cout << i << " " << seen[i][0] << " " << seen[i][1] << endl;
  }
}

void dfs(const vector<vector<int>> &G, int v, vector<vector<int>> &seen){
  seen[v][0] = cnt++;
  for(auto n_v : G[v]){
    if(seen[n_v][0] != 0) continue;
    dfs(G, n_v, seen);
  }
  seen[v][1] = cnt++;
}