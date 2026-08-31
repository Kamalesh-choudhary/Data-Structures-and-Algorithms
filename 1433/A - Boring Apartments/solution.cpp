#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int t;
  cin >> t;
  while(t--){
    string x;
    cin >> x;
    int n = x.size();
    int ans = 0;
    int curr = x[0]-'0';
    for (int i=1;i<curr;i++){
      string temp = "";
      while (temp.size()<4){
        ans += temp.size()+1;
        temp += to_string(i);
      }
    }
    for (int i=0;i<n;i++){
      ans += i+1;
    }
    cout << ans << endl;
  }
}