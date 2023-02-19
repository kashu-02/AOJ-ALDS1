#include <iostream>
#include <string>

#define M 1000003

using namespace std;

long long hashTable[M];

long long hash1(int);
long long hash2(int);
int getChar(char);
int getKey(string);
void insert(string);
string find(string);

int main(){
  int n;
  cin >> n;
  for(int i = 0; i < n; i++){
    string com, str;
    cin >> com >> str;
    if(com == "insert"){
      insert(str);
    }else{
      cout << find(str) << endl;
    }
  }
}

long long hash1(int key){ return key % M; }
long long hash2(int key){ return 1+(key % (M-1)); }

int getChar(char c){
  if(c == 'A') return 1;
  else if(c == 'C') return 2;
  else if(c == 'G') return 3;
  else if(c == 'T') return 4;
  return 0;
}

int getKey(string s){
  int sum = 0, p = 1;
  for(int i = 0; i < s.size(); i++){
    sum += p * (getChar(s[i]));
    p *= 5;
  }
  return sum;
}


void insert(string s){
  int key;
  long long h;
  key = getKey(s);
  for(int i = 0; ; i++){
    h = (hash1(key) + i * hash2(key)) % M;
    if(hashTable[h] == 0){
      hashTable[h] = key;
      return;
    }
  }
}

string find(string s){
  int key;
  long long h;
  key = getKey(s);
  for(int i = 0; ; i++){
    h = (hash1(key) + i * hash2(key)) % M;
    if(hashTable[h] == key) return "yes";
    else if(hashTable[h] == 0) return "no";
  }
}