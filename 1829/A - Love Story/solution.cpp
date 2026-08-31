#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int t;
  cin >> t;
  while(t--){
    string s;
    int count = 0;
    cin >> s;
    string codeforces = "codeforces";
    for (int i=0;i<s.size();i++){
      if (s[i] != codeforces[i]){
        count += 1;
      }
    }
    cout << count << endl;
  }
}