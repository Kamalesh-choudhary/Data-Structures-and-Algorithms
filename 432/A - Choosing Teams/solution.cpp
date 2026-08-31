#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int n,k;
  cin >> n >> k;
  vector<int> arr(n);
  vector<int> allowed;
  for (auto &x:arr){
    cin >> x;
    if ((x+k)<=5){
      allowed.push_back(x);
    }
  }
  int size = allowed.size()/3;
  cout << size << endl;
 
}