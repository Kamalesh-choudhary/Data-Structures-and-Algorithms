#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int t;
  cin >> t;
  while (t--){
    int a,b,c;
    cin >> a >> b >> c;
    bool flag = false;
    if (a== (b+c)){
      flag = true;
    }
    if (b==(a+c)){
      flag = true;
    }
    if (c == (b+a)){
      flag = true;
    }
    if (flag){
      cout << "YES" << endl;
    }
    else{
      cout << "NO" << endl;
    }
  }
}