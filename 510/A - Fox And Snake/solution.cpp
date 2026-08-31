#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int n,m;
  bool order = false;
  cin >> n >> m;
  for (int i=0;i<n;i++){
    for (int j=0;j<m;j++){
      if ((i&1) == 0){
        cout << "#";
      }
      else{
        if (order){
          if (j==0){
            cout << "#";
          }
          else{
            cout << ".";
          }
        }
        else{
          if (j<m-1){
            cout << ".";
          }
          else{
            cout << "#";
          }
        }
      }
    }
    cout << endl;
    if ((i&1) != 0) order = !order;
  }
}