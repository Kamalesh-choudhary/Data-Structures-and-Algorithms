#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    vector<int> vec(n);
    for(auto &x:vec) cin >> x;
    int ans = 0;
    int space = 0;
    for (int i=0;i<n;i++){
      if (vec[i]==0){
        space += 1;
        ans = max(space,ans);
      }
      else{
        space = 0;
      }
    }
    cout << ans << endl;
  }
}