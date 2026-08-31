#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int t;
  cin >> t;
  while (t--){
    int x,y;
    cin >> x >> y;
    string yes = "YES";
    string no = "NO";
    if ((x&1)!=0 && (y&1)!=0) cout << no << endl;
    else cout << yes << endl;
  }
}