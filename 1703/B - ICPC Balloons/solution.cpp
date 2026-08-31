#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    string s;
    int ans = 0;
    cin >> s;
    set<char> alpha;
    for (auto &x:s){
      if (alpha.count(x)){
        ans += 1;
      }
      else{
        ans += 2;
        alpha.insert(x);
      }
    }
    cout << ans << endl;
  }
}