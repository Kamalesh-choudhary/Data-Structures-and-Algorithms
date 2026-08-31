#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  while(t--){
    long long n, m;
    cin >> n >> m;
    vector<long long> a(n);
    for(auto& x:a) cin>>x;
 
    bool no = false;
    int cnt = 1;
    for(int i = 1; i < n; i++){
      if(a[i] == a[i-1]) cnt++;
      else cnt = 1;
      if(cnt >= m){
        no = true;
        break; 
      }
    }
    cout << (no ? "NO" : "YES") << "
";
  }
}