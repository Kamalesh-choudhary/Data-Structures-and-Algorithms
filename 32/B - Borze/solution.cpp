#include <bits/stdc++.h>
using namespace std;
 
int main(){
  string s;
  string ans = "";
  cin >> s;
  int i=0;
  while (i<s.size()){
    if (s[i] == '.'){
      ans += '0';
      i+=1;
    }
    else{
      if (s[i+1]=='.'){
        ans += '1';
      }
      else{
        ans += '2';
      }
      i+=2;
    }
  }
  cout << ans << endl;
}