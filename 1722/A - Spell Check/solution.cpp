#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    string s;
    cin >> s;
    unordered_map<char,int> timur = {{'T',1},{'i',1},{'m',1},{'u',1},{'r',1}};
    unordered_map<char,int> map;
    for (auto &x:s){
      if (map.count(x)){
        map[x] += 1;
      }
      else{
        map[x] = 1;
      }
    }
    if (timur == map){
      cout << "YES" << endl;
    }
    else{
      cout << "NO" << endl;
    }
  }
}