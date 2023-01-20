#include <iostream>

using namespace std;

struct Node{
  int key = -1;
  int parent = -1;
  int left = -1;
  int right = -1;
};

int main(){
  int H;
  cin >> H;
  Node node[H + 1];

  for(int i = 1; i <= H; i++){
    cin >> node[i].key;
    if(i != 1) node[i].parent = (int)(i / 2);
    if(2 * i <= H) node[i].left = 2 * i;
    if((2 * i + 1) <= H) node[i].right = 2 * i +1;
  }
  

  for(int i = 1; i <= H; i++){
    cout << "node " << i << ": key = " << node[i].key << ", ";
    if(node[i].parent != -1){
      cout << "parent key = " << node[node[i].parent].key << ", ";
    }
    if(node[i].left != -1){
      cout << "left key = " << node[node[i].left].key << ", ";
    }
    if(node[i].right != -1){
      cout << "right key = " << node[node[i].right].key << ", ";
    }
    cout << endl;
  }


  return 0;
}