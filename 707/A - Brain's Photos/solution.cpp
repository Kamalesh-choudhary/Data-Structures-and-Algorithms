#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int n,m;
  cin >> n >> m;
  vector<vector<char>> matrix;
  set<char> colors;
  for (int i=0;i<n;i++){
    vector<char> temp;
    for (int j=0;j<m;j++){
      char x;
      cin >> x;
      temp.push_back(x);
      colors.insert(x);
    }
    matrix.push_back(temp);
  }
  colors.erase('B');
  colors.erase('W');
  colors.erase('G');
  if (colors.empty()){
    cout << "#Black&White" << endl;
  }
  else{
    cout << "#Color" << endl;
  }
}