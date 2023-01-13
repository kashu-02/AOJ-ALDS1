#include <iostream>

using namespace std;

struct Node{
  int parent = -1;
  int left_child = -1;
  int right_child = -1;
};

int depth_calc(Node *, int);
int height_calc(Node *, int);
int deg_calc(Node *, int);
int get_sibling(Node *, int);


int main(){
  int n;
  cin >> n;
  Node tree[n];
  for(int i = 0; i < n; i++){
    int num, left, right;
    cin >> num;
    cin >> left >> right;
    tree[num].left_child = left;
    tree[num].right_child = right;
    tree[left].parent = num;
    tree[right].parent = num;
  }

  for(int i = 0; i < n; i++){
    cout << "node " << i << ": parent = " << tree[i].parent << ", sibling = " << get_sibling(tree, i) << ", degree = " << deg_calc(tree, i) << ", depth = " << depth_calc(tree, i) << ", height = " << height_calc(tree, i);
    if(tree[i].parent == -1){
      cout << ", root" << endl;
    }else if(tree[i].left_child == -1 && tree[i].right_child == -1){
      cout << ", leaf" << endl;
    }else{
      cout << ", internal node" << endl;
    }
  }
}

int depth_calc(Node *tree, int number){
  int depth = 0, i = number;
  while(1)
  {
    if(tree[i].parent == -1) break;
    i = tree[i].parent;
    depth++;
  }

  return depth;
}

int height_calc(Node *tree, int number){
  if(number == -1)
    return -1;
  int left_height = height_calc(tree, tree[number].left_child);
  int right_height = height_calc(tree, tree[number].right_child);

  return 1 + (left_height > right_height ? left_height : right_height);
}

int deg_calc(Node *tree, int number){
  if(tree[number].left_child != -1 && tree[number].right_child != -1)
    return 2;
  else if(tree[number].left_child != -1 || tree[number].right_child != -1)
    return 1;
  else
    return 0;
}

int get_sibling(Node *tree, int number){
  if(tree[number].parent == -1) return -1;
  if (tree[tree[number].parent].left_child == number) return tree[tree[number].parent].right_child;
  if (tree[tree[number].parent].right_child == number) return tree[tree[number].parent].left_child;
  return -1;
}