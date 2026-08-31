#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int n;
  cin >> n;
  vector<int> vec(n);
  int maximum = -1;
  for(auto &x:vec){
    cin >> x;
    maximum = max(maximum,x);
  }
  int ans = 0;
  for (int i=0;i<n;i++){
    ans += maximum - vec[i];
  }
  cout << ans << endl;
}