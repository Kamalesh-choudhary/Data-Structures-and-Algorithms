#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int t;
  cin >> t;
  while(t--){
    string s;
    cin >> s;
    int n = 5;
    int a = 0;
    int b = 0;
    for (auto x:s){
      if (x=='A'){
        a++;
      }
      else{
        b++;
      }
    }
    if (a>b){
      cout << "A" << endl;
    }
    else{
      cout << "B" << endl;
    }
  }
}