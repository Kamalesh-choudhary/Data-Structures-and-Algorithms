#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int t;
  cin >> t;
  while (t--){
    int n;
    cin >> n;
    vector<int> ans;
    int counter = 1;
    while (n>0){
      int last = n%10;
      n = n/10;
      last = last * counter;
      counter *= 10;
      if (last > 0){
        ans.push_back(last);
      } 
    }
    cout << ans.size() << endl;
    for (auto &x:ans) cout << x << " ";
    cout << endl;
  }
}