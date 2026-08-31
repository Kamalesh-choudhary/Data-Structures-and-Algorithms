#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int t;
  cin >> t;
  while (t--){
    int n;
    cin >> n;
    long long ans = -1;
    vector<long long> ar(n);
    for (auto &x:ar) cin >> x;
    vector<int> primes = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53};
    for (auto p:primes){
      for (int j=0;j<n;j++){
        if ((ar[j]%p)!=0){
          ans = p;
          break;
        }
      }
      if (ans != -1){
        break;
      }
    }
    if (ans!=-1){
      cout << ans << endl;
    }
    else{
      cout << -1 << endl;
    }
  }
}