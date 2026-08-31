#include <bits/stdc++.h>
using namespace std;
 
int main(){
  string s;
  cin >> s;
  int mask = 0;
 
  for (char c: s){
    if (c=='1') mask+= (1<<0);
    else if (c=='2') mask += (1<<7);
    else if (c== '3') mask += (1<<14);
  }
 
  int c1 = (mask >> 0) & ((1<<7)-1);
  int c2 = (mask >> 7) & ((1<<7)-1);
  int c3 = (mask >> 14) & ((1<<7)-1);
 
  bool first = true;
  while (c1--){
    if (!first) cout << "+";
    cout << "1";
    first = false;
  }
  while (c2--){
    if (!first) cout << "+";
    cout << "2";
    first = false;
  }
  while (c3--){
    if (!first) cout << "+";
    cout << "3";
    first = false;
  }
  cout << endl;
}
  