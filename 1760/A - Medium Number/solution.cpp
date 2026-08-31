#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int t;
  cin >> t;
  while(t--){
    vector<int> ar(3);
    int maximum=INT_MIN;
    int minimum = INT_MAX;
    for (auto &x:ar){
      cin >> x;
      maximum = max(maximum,x);
      minimum = min(minimum,x);
    }
    for (auto x:ar){
      if (x!=maximum && x!=minimum){
        cout << x << endl;
        break;
      }
    }
  }
}