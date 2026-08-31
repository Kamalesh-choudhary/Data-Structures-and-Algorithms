#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main(){
  int t;
  cin >> t;
  while(t--){
    ll x,y;
    cin >> x >> y;
    if (x*2 < y){
      cout << "YES" << endl;
    }
    else{
      cout << "NO" << endl;
    }
  }
}