#include <iostream>
#include <string>

using namespace std;

struct Node{
  int key;
  Node *parent;
  Node *left;
  Node *right;
};

Node *root = new Node;
string out1, out2;

void insert(int);
void preorder(Node *);
void inorder(Node *);

int main()
{
  root = NULL;
  int m;
  cin >> m;
  for (int i = 0; i < m; i++)
  {
    string command;
    int k;
    cin >> command;
    if(command == "insert"){
      cin >> k;
      insert(k);
    }
    if(command == "print"){
      inorder(root);
      cout << endl;
      preorder(root);
      cout << endl;
    }
  }
}


void insert(int num){
  Node *y = NULL;
  Node *x = root;

  Node *z = new Node;
  z->key = num;
  while (x != NULL)
  {
    y = x;
    if(z->key < x->key){
      x = x->left;
    }else{
      x = x->right;
    }
  }
  z->parent = y;

  if(y == NULL){
    root = z;
  }else if(z->key < y->key){
    y->left = z;
  }else{
    y->right = z;
  }
}

void preorder(Node *x){
  if(x == NULL){
    return;
  }
  cout << " " << x->key;
  if(x->left != NULL)
    preorder(x->left);
  if (x->right != NULL)
    preorder(x->right);
}

void inorder(Node *x){
  if(x == NULL){
    return;
  }
  if(x->left != NULL)
    inorder(x->left);
  cout << " " << x->key;
  if (x->right != NULL)
    inorder(x->right);
}