#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    vector<int> ar(n);
    for (auto &x:ar) cin >> x;
    unordered_map<int,int> map;
    int ans = 0;
    for (int i=0;i<n;i++){
      if (map.count(ar[i])){
        map[ar[i]]++;
      }
      else{
        map[ar[i]] = 1;
      }
      if (map[ar[i]] == 3){
        ans = ar[i];
        break;
      }
    }
    if (ans == 0){
      cout << -1 << endl;
    }
    else{
      cout << ans << endl;
    }
  }
}