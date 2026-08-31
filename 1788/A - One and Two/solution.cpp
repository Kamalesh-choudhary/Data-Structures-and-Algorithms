#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    int count = 0;
    vector<int> ar(n);
    for (auto &x:ar){
      cin >> x;
      if (x==2){
        count++;
      }
    }
    if ((count & 1)!=0){
      cout << -1 << endl;
      continue;
    }
    int half = count/2;
    for (int i=0;i<n;i++){
      if (ar[i] == 2){
        count --;
      }
      if (count == half){
        cout << i+1 << endl;
        break;
      }
    }
  }
}