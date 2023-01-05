#include <iostream>
using namespace std;

struct Card{
  char pattern;
  int number;
};

void quicksort(Card *, int, int);
int partition(Card *card, int p, int r);

int main(){
  int n;
  cin >> n;
  Card card[n];
  for(int i = 0; i < n; i++){
    cin >> card[i].pattern >> card[i].number;
  }

  quicksort(card, 0, n - 1);

  for(int i = 1; i < n; i++){
    cout << card->pattern << " " << card->number << endl;
  }
}

void quicksort(Card *card, int p, int r){
  if(p < r){
    int q = partition(card, p, r);
    quicksort(card, p, q - 1);
    quicksort(card, q + 1, r);
  }
}

int partition(Card *card, int p, int r){
  Card x = card[r];
  int i = p - 1;
  for(int j = p; j < r; j++){
    if(card[j].number <= x.number){
      i++;
      swap(card[i], card[j]);
    }
  }
  swap(card[i + 1], card[r]);
  return i + 1;
}