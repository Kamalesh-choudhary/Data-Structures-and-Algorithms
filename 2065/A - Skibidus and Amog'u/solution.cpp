#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int t;
  cin >> t;
  while(t--){
    string s;
    cin >> s;
    int n = s.size();
    string ans = s.substr(0,n-2)+'i';
    cout << ans << endl;
  }
}