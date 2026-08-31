#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    string a,b;
    cin >> a;
    cin >> b;
    bool flag = true;
    
    for (int i=0;i<n;i++){
      if ((a[i]=='R' && b[i]!='R') || (a[i]!='R' && b[i]=='R')){
        flag = false;
        break;
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