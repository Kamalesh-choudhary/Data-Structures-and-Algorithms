#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int t;
  cin >> t;
  while (t--){
    int n;
    cin >> n;
    string s;
    cin >> s;
    char ans = s[0];
    for (int i=0;i<n;i++){
      ans = max(ans,s[i]);
    }
    int answer = ans-'a'+1;
    cout << answer << endl;
  }
}