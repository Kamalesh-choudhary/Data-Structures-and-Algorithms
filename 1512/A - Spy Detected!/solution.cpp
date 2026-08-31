#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    unordered_map<int,pair<int,int>> map;
    vector<int> ar(n);
    for(int i=0;i<n;i++) {
      cin >> ar[i];
      if (!map.count(ar[i])){
        map[ar[i]] = {i,1}; 
      }
      else{
        map[ar[i]].second+= 1;
      }
    }
    for(auto &[key,val]:map){
      if (val.second==1){
        cout << val.first+1 << endl;
        break;
      }
    }
  }
}