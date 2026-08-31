#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int n;
  cin >> n;
  vector<int> ar(n);
  for (auto &x:ar) cin >> x;
  int ans = 0;
  int current = 0;
  for (int i=0;i<n-1;i++){
    if (ar[i] < ar[i+1]){
      current++;
    }
    else{
      ans = max(ans,current);
      current = 0;
    }
  }
  ans = max(ans,current)+1;
  cout << ans << endl;
}