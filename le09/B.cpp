#include <iostream>
#include <climits>

using namespace std;

void maxHeapify(int *, int);

int H;

int main(){

  cin >> H;
  int arr[H+1];
  arr[0] = -1;
  for (int i = 1; i <= H; i++)
  {
    cin >> arr[i];
  }
  for (int i = H / 2; i >= 1; i--)
  {
    maxHeapify(arr, i);
  }

  for (int i = 1; i <= H; i++){
    cout << " " << arr[i];
  }
  cout << endl;
}

void maxHeapify(int *arr, int i){
  int r, l, largest;
  if(i * 2 <= H){
    l = i * 2;
  }else{
    l = INT_MAX;
  }
  if(i * 2 + 1 <= H){
    r = i * 2 + 1;
  }else{
    r = INT_MAX;
  }
  if (l <= H && arr[l] > arr[i]){
    largest = l;
  }else{
    largest = i;
  }
  if(r <= H && arr[r] > arr[largest]){
    largest = r;
  }
  if(largest != i){
    swap(arr[i], arr[largest]);
    maxHeapify(arr, largest);
  }
  
}