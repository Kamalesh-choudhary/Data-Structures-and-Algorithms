#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int n;
  cin >> n;
  vector<int> ar(n);
  for (auto &x:ar) cin >> x;
  int count = 0;
  int answer = 0;
  for (int i=0;i<n;i++){
    if (ar[i] > 0){
      if (count < 0){
        count = -count;
        answer += count;
        count = 0;
      }
      count += ar[i];
    }
    else{
      count -= 1;
    }
  }
  if (count < 0){
    count = -count;
    answer += count;
  }
  cout << answer << endl;
}