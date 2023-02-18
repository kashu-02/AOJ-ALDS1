#include <iostream>
#include <string>

using namespace std;

struct Node{
  Node* prev;
  Node* next;
  int key;
};

Node *head = NULL;
Node *tail = NULL;

void insertKey(int);
void list();
void deleteKey(int);
void deleteFirst();
void deleteLast();

int main(){
  int n;
  cin >> n;
  for(int i = 0; i < n; i++){
    string command;
    cin >> command;
    if(command == "insert"){
      int key;
      cin >> key;
      insertKey(key);
    }
    else if(command == "delete"){
      int key;
      cin >> key;
      deleteKey(key);
    }
    else if(command == "deleteFirst"){
      deleteFirst();
    }
    else if(command == "deleteLast"){
      deleteLast();
    }
  }

  list();


}

void insertKey(int key){
  Node *node = (Node *)malloc(sizeof(Node));
  node->key = key;
  node->next = NULL;
  node->prev = NULL;
  if(head == NULL){
    head = node;
    tail = node;
  }
  else{
    node->next = head;
    head->prev = node;
    head = node;
  }
}

void deleteKey(int key){
  Node *node = head;
  while(node != NULL){
    if(node->key == key){
      if(node->prev != NULL){
        node->prev->next = node->next;
      }
      else{
        head = node->next;
      }
      if(node->next != NULL){
        node->next->prev = node->prev;
      }
      else{
        tail = node->prev;
      }
      free(node);
      break;
    }
    node = node->next;
  }
}

void deleteFirst(){
  Node *node = head;
  if(node != NULL){
    head = node->next;
    if(head != NULL){
      head->prev = NULL;
    }
    else{
      tail = NULL;
    }
    free(node);
  }
}

void deleteLast(){
  Node *node = tail;
  if(node != NULL){
    tail = node->prev;
    if(tail != NULL){
      tail->next = NULL;
    }
    else{
      head = NULL;
    }
    free(node);
  }
}

void list(){
  Node *node = head;
  while(node->next != NULL){
    cout << node->key << " ";
    node = node->next;
  }
  cout << node->key << endl;
}
