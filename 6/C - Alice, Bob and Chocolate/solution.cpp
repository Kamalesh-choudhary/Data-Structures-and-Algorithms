#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int n;
  cin >> n;
  vector<int> v(n);
  for (auto &x: v) cin >> x;
  
  int left = 0;
  int right = v.size()-1;
  int timeA = 0,timeB = 0;
  int countA = 0,countB = 0;
  while (left <= right){
    if (timeA <= timeB){
      timeA += v[left];
      left++;
      countA++;
    }
    else{
      timeB += v[right];
      right--;
      countB++;
    }
  }
  cout << countA << " " << countB << endl;
  
}