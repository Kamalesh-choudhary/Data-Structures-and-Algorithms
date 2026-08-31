#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int t;
  cin >> t;
  while(t--){
    string b;
    cin >> b;
    string ans = "";
    ans += b[0];
    int i=1;
    while (i<b.size()){
      if (b[i] == b[i+1]){
        ans += b[i];
        i+=2;
      }
      else{
        ans += b[i];
        i+=1;
      }
    }
    cout << ans << endl;
  }
}