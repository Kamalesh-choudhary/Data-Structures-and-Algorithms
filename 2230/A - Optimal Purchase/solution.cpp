#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
 
  int t;
  cin >> t;
  while(t--){
    ll n,a,b;
    cin >> n >> a >> b;
 
    if(n>3){
      ll total = 0;
      ll parts = n/3;
      total += parts*b;
      ll remaining = n%3;
      total += min(remaining*a,b);
      cout << min(total,n*a) << endl;
    }
    else{
      cout << min(n*a,b) << endl;
    }
  }
}