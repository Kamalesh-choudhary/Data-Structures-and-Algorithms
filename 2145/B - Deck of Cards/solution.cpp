#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int t;
  cin >> t;
  while (t--){
    int n,k;
    cin >> n >> k;
    string s;
    cin >> s;
    int zero=0,one = 0,two = 0;
    for (auto ch:s){
      if (ch=='0'){
        zero += 1;
      }
      else if (ch == '1'){
        one+= 1;
      }
      else if (ch == '2'){
        two += 1;
      }
    }
    string ans(n,'+');
    for (int i=0;i<n;i++){
      if ((i<(zero+two)) || (i>= (n-one-two))){
        ans[i] = '?';
      }
      if ((i<zero) || (i>=(n-one)) || k == n){
        ans[i] = '-';
      }
    }
    cout << ans << endl;
  }
}