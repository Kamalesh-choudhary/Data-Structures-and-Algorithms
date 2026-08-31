#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int t;
  cin >> t;
  while(t--){
    char c;
    cin >> c;
    bool flag = false;
    string codeforces = "codeforces";
    for (auto &ch:codeforces){
      if (ch==c){
        flag = true;
      }
    }
    if (flag){
      cout << "YES" << endl;
    }
    else{
      cout << "NO" << endl;
    }
  }
}