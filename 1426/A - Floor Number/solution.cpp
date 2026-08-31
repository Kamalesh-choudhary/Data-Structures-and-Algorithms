#include <bits/stdc++.h>
using namespace std;
 
int solve(int n,int x){
  if ((n-2)<=0){
    return 1;
  }
  n = n-3;
  int temp = n/x;
  return temp+2;
}
 
int main(){
  int t;
  cin >> t;
  while(t--){
    int n,x;
    cin >> n >> x;
    cout << solve(n,x) << endl;
  }
}