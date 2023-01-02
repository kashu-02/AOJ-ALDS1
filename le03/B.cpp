#include <iostream>

using namespace std;


typedef struct{
  char name[10];
  int time;
} Process;

typedef struct NODE{
  Process process;
  struct NODE *next;
} nodePointer;

nodePointer *head;
nodePointer *tail;

int main(){
  int n, q;
  cin >> n >> q;

  for (int i = 0; i < n; i++){
    nodePointer *node;

    node = (nodePointer *)malloc(sizeof(nodePointer));
    cin >> node->process.name >> node->process.time;
    node->next = NULL;
    if (head == NULL)
      head = node;
    if(tail != NULL){
      tail->next = node;
    }
    tail = node;
  }

  int time_c = 0;
  while (head != NULL){
    int aa = head->process.time - q;
    if (aa <= 0){
      time_c += head->process.time;
      cout << head->process.name << " " << time_c << endl;
      nodePointer *del_node = head;
      head = head->next;
      free(del_node);
    }
    else{
      time_c += q;
      head->process.time = aa;
      if(head->next != NULL){
        nodePointer *push_node = head;
        head = head->next;
        push_node->next = NULL;
        tail->next = push_node;
        tail = push_node;
      }
    }
  }
}
