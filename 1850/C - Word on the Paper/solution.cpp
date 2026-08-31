#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int t;
  cin >> t;
  while (t--){
    string ans = "";
    vector<vector<char>> matrix;
    for (int i=0;i<8;i++){
      vector<char> temp(8);
      for (auto &x:temp){
        cin >> x;
        if (x!='.'){
          ans += x;
        }
      }
      matrix.push_back(temp);
    }
    cout << ans << endl;
  }
}