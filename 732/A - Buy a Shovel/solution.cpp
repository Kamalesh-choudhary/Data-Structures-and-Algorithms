#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int k,r;
  cin >> k >> r;
  int answer;
  for (int i=1;i<1000;i++){
    int current_sum = k*i;
    if (((current_sum % 10)==0) || (((current_sum-r)%10)==0)){
      answer = i;
      break;
    }
  }
  cout << answer << endl;
}