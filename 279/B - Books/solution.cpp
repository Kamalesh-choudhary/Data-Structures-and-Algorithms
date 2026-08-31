#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int n,t;
  cin >> n >> t;
  vector<int> vec(n);
  for (auto &x: vec) cin >> x;
  
  int book = 0;
  int left = 0,right = 0;
  int sum = 0;
  while (right < n){
    sum += vec[right];
    while (sum > t){
      sum -= vec[left];
      left++;
    }
    book = std::max(book,right-left+1);
    right += 1;
  }
  cout << book << endl;
 
}