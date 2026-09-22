#include <bits/stdc++.h>
using namespace std;
 
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
 
  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    vector<int> ar(n);
    for(auto &x:ar) cin >> x;
    
    int c0 = 0,c1 = 0,c2 = 0;
    for(int i=0;i<n;i++){
      if (ar[i] == 0){
        c0++;
      }
      else if (ar[i] == 1){
        c1 ++;
      }
      else{
        c2++;
      }
    }
    int count = min(c1,c2);
    c1 -= count;
    c2 -= count;
    count += c1/3;
    count += c2/3;
    count += c0;
    cout << count << endl;
  }
}