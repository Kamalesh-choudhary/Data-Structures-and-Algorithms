#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    string s;
    cin >> s;
    string yes = "YES";
    string no = "NO";
    int count = 0;
    for(auto ch:s){
      if (ch == '(') count++;
      else count--;
    }
    if (count == 0)cout << yes << endl;
    else cout << no << endl;
  }
}