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
    int left = 0;
    int right = n-1;
    while ((left < right) && ((s[left]=='0') && (s[right]=='1') || (s[left]=='1') && (s[right]=='0'))){
      left += 1;
      right -= 1;
    }
    cout << right-left+1 << endl;
  }
}