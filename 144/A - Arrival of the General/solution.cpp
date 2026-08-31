#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int n;
  cin >> n;
  vector<int> arr(n);
  for (auto &x: arr) cin >> x;
  int seconds = 0;
  int minimum = 0,maximum = 0;
  for (int i=0;i<n;i++){
    if (arr[minimum] >= arr[i]){
      minimum = i;
    }
    if (arr[maximum] < arr[i]){
      maximum = i;
    }
  }
  seconds = maximum + (n-minimum-1);
  if (maximum > minimum){
    seconds--;
  }
  cout << seconds << endl;
}