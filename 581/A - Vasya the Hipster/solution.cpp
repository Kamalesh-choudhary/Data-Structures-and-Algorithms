#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int a,b;
  cin >> a >> b;
  int max_diff = min(a,b);
  int remaining = max(a,b)-min(a,b);
  int max_same = remaining/2;
  cout << max_diff << " " << max_same << endl;
}