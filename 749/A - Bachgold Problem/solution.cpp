#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int n;
  cin >> n;
  vector<int> ans;
  while (n>=2){
    if (n==3){
      ans.push_back(3);
      break;
    }
    ans.push_back(2);
    n-=2;
  }
 
  cout << ans.size() << endl;
  for (auto &x:ans) cout << x << " ";
  cout << endl;
}