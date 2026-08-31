#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int n,k;
  cin >> n >> k;
  int problems = 0;
  int summ = 0;
  for (int i=0;i<n;i++){
    int total_time = 5*(i+1);
    summ += total_time;
    if ((summ + k) <= 240){
      problems += 1;
    }
    else{
      break;
    }
  }
  cout << problems << endl;
}