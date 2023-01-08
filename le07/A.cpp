#include <iostream>
#include <vector>

using namespace std;

struct Node{
  int parent = -1;
  int child = -1;
  int next_sibling = -1;
};

int depth_calc(Node *, int);

int main(){
  int n;
  cin >> n;
  Node tree[n];
  for(int i = 0; i < n; i++){
    int num, k;
    cin >> num >> k;
    int children[k];
    for (int j = 0; j < k; j++){
      cin >> children[j];
    }
    if(k != 0){
      tree[num].child = children[0];
      if(k == 1){
        tree[children[0]].parent = num;
      }
      for (int j = 1; j < k; j++){
        tree[children[j - 1]].parent = num;
        tree[children[j - 1]].next_sibling = children[j];
      }
    }
  }

  for(int i = 0; i < n; i++){

    cout << "node " << i << ": parent = " << tree[i].parent << ", depth = " << depth_calc(tree, i);
    if(tree[i].parent == -1){
      cout << ", root";
    }else if(tree[i].child == -1){
      cout << ", leaf";
    }else{
      cout << ", internal node";
    }
    cout << ", [";
    if(tree[i].child != -1){
      cout << tree[i].child;
      for(int c_num = tree[i].child; c_num != -1; c_num = tree[c_num].next_sibling){
        cout << ", " << c_num;
      }
    }
    cout << "]" << endl;
  }
}

int depth_calc(Node *tree, int number){
  int depth;
  for (int i = number; i != 0; i = tree[i].parent)
  {
    if(tree[i].parent == -1) break;
    depth++;
  }

  return depth;
}