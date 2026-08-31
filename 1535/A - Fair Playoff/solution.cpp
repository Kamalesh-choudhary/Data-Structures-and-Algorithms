#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int t;
  cin >> t;
  while(t--){
    vector<int> input(4);
    for (auto &x:input) cin >> x;
    if ((max(input[0],input[1])>min(input[2],input[3])) && (max(input[2],input[3])>min(input[0],input[1]))){
      cout << "YES" << endl;
    }
    else{
      cout << "NO" << endl;
    }
  }
}