#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int t;
  cin >> t;
  while(t--){
    vector<int> values(3);
    unordered_map<int,int> map;
    for (auto &x:values){
      cin >> x;
      map[x]++;
    }
    for (auto &[key,val]:map){
      if (val==1){
        cout << key << endl;
        break;
      }
    }
  }
}