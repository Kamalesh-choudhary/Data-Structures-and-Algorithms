#include <bits/stdc++.h>
using namespace std;
 
int main(){
  vector<int> values(4);
  for (auto &x:values) cin >> x;
  string s;
  cin >> s;
  int total = 0;
  for (int i=0;i<s.size();i++){
    if (s[i]=='1'){
      total += values[0];
    }
    else if (s[i] == '2'){
      total += values[1];
    }
    else if (s[i] == '3'){
      total += values[2];
    }
    else{
      total += values[3];
    }
  }
  cout << total << endl;
}