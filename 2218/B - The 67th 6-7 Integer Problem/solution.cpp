#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int t;
  cin >> t;
  while(t--){
    vector<int> integers(7);
    int ans = INT_MIN;
    int summ = 0;
    int maximum = INT_MIN;
    for(auto &x:integers){
      cin >> x;
      summ += x;
      maximum = max(maximum,x);
    }
    ans = summ - (2*maximum);
    cout << ans*(-1) << endl;
  }
}