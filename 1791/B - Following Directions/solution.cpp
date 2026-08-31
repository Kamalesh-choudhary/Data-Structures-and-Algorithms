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
    int i=0,j=0;
    bool flag = false;
    for (int x=0;x<n;x++){
      if (s[x] == 'U'){
        i++;
      }
      else if (s[x] == 'D'){
        i--;
      }
      else if (s[x] == 'L'){
        j--;
      }
      else if (s[x] == 'R'){
        j++;
      }
      if (i==1 && j==1){
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