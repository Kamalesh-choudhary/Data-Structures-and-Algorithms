#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int n;
  cin >> n;
  vector<int> g1,g2,g3;
  for (int i=0;i<n;i++){
    int x;
    cin >> x;
    if (x==1) g1.push_back(i+1);
    else if (x==2) g2.push_back(i+1);
    else g3.push_back(i+1);
  }
  int teams = min({g1.size(),g2.size(),g3.size()});
  cout << teams << endl;
  for (int i=0;i<teams;i++){
    cout << g1[i] << " " << g2[i] << " " << g3[i] << endl;
  }
}