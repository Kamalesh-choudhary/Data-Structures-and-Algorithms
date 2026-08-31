#include <bits/stdc++.h>
using namespace std;
 
int main(){
  char ch;
  set<char> arr;
  cin >> ch;
  char x;
  while (true){
    cin >> x;
    if (x == '}'){
      break;
    }
    arr.insert(x);
    cin >> ch;
    if (ch == '}'){
      break;
    }
  }
  if (arr.empty()){
    cout << 0 << endl;
  }
  else{
    cout << arr.size() << endl;
  }
}