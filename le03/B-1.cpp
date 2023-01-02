/*
 * AOJ ALDS1_3_B Queue
 * Vectorで実装したけど、一番最後がTLEになってボツになった。
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Process {
  char name[10];
  int time;
};

int main(){
  int n, q;
  cin >> n >> q;

  vector<Process> pp(n);

  for(int i = 0; i < n; i++){
    cin >> pp[i].name >> pp[i].time;
  }

  int time_c = 0;
  while(pp.size() > 0){
    int aa = pp[0].time - q;
    if(aa <= 0){
      time_c += pp[0].time;
      cout << pp[0].name << " " << time_c << endl;
      pp.erase(pp.begin());
    }else{
      time_c += q;
      pp[0].time = aa;
      pp.push_back(pp[0]);
      pp.erase(pp.begin());
    }
  }

}