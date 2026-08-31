#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    vector<int> ar(n);
    bool flag = true;
    for(auto &x:ar) cin >> x;
    sort(ar.begin(),ar.end());
    set<int> temp;
    for(int i=0;i<n;i++){
      if (temp.find(ar[i]) != temp.end()){
        flag = false;
        break;
      }
      else{
        temp.insert(ar[i]);
      }
    }
    if (flag){
      for(int i=n-1;i>=0;i--){
        cout << ar[i] << " ";
      }
      cout << endl;
    }
    else{
      cout << -1 << endl;
    }
  }
}