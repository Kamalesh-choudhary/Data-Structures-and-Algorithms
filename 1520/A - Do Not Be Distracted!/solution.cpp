#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    string s;
    cin >> s;
    set<int> check;
    int i=0;
    bool flag = true;
    while (i<n){
      if (!check.count(s[i])){
        char temp = s[i];
        check.insert(s[i]);
        while (temp == s[i]){
          i++;
        }
      }
      else{
        i++;
        flag = false;
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