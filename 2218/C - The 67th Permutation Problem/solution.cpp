#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    int k = 3*n;
    for(int i=1;i<=n;i++){
      cout << k << " " << k-1 << " " << i << " ";
      k -= 2;
    }
    cout << endl;
  }
}