#include <bits/stdc++.h>
using namespace std;
 
int main(){
  string guest,host,letters;
  cin >> guest;
  cin >> host;
  cin >> letters;
 
  unordered_map<char,int> map1;
  unordered_map<char,int> map2;
 
  for (char ch: guest){
    map1[ch] += 1;
  }
  
  for (char ch: host){
    map1[ch] += 1;
  }
 
  for (char ch: letters){
    map2[ch] += 1;
  }
 
  if (map1 == map2){
    cout << "YES" << endl;
  }
  else{
    cout << "NO" << endl;
  }
}