#include <bits/stdc++.h>
using namespace std;
 
vector<int> level(1001);
 
int main(){
  level[0] = 0;
  level[1] = 1;
  level[2] = 3;
  for (int i=3;i<level.size();i++){
    level[i] = level[i-1]+i;
  }
  int n;
  cin >> n;
  int i=1;
  int summ = 0;
  while(summ+level[i] <= n){
    summ += level[i];
    i+=1;
  }
  cout << i-1 << endl;
}