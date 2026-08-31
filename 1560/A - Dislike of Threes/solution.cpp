#include <bits/stdc++.h>
using namespace std;
 
vector<int> pos;
 
 
int main(){
  int t;
  for (int i=1;i<2000;i++){
    if (((i%3)!=0) && ((i%10)!=3)){
      pos.push_back(i);
    }
  }
  cin >> t;
  while(t--){
    int k;
    cin >> k;
    cout << pos[k-1] << endl;
  }
}