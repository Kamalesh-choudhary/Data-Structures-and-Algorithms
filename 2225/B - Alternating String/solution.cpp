#include <bits/stdc++.h>
using namespace std;
 
bool canFix(string s,string target){
  int n = s.size();
  int first = -1;
  int last = -1;
  for(int i=0;i<n;i++){
    if (s[i] != target[i]){
      if (first == -1)first = i;
      last = i;
    }
  }
  if (first == -1) return true;
 
  for(int i=first;i<=last;i++){
    if (s[i] == target[i]) return false;
  }
  return true;
}
 
int main(){
  int t;
  cin >> t;
  while(t--){
    string s;
    cin >> s;
    string result = "NO";
    int count = 0;
    int n = s.size();
    string t1 = "",t2 = "";
    for(int i=0;i<n;i++){
      t1 += (i%2==0)? 'a':'b';
      t2 += (i%2==0)? 'b':'a';
    }
    if (canFix(s,t1) || canFix(s,t2)){
      cout << "YES" << endl;
    }
    else{
      cout << "NO" << endl;
    }
  }
}