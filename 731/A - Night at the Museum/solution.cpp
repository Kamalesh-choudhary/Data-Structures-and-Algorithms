#include <bits/stdc++.h>
using namespace std;
 
int main(){
  string name;
  cin >> name;
 
  int current = 0;
  int total = 0;
 
  for (char ch:name){
    int target = ch-'a';
    int dif = abs(target-current);
    total += min(dif,26-dif);
    current = target;
  }
  cout << total << endl;
}