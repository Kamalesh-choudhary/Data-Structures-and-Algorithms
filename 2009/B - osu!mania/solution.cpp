#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    vector<vector<char>> matrix;
    for (int i=0;i<n;i++){
      vector<char> temp;
      for (int j=0;j<4;j++){
        char x;
        cin >> x;
        temp.push_back(x);
      }
      matrix.push_back(temp);
    }
    for (int i=n-1;i>=0;i--){
      for (int j=0;j<4;j++){
        if (matrix[i][j] == '#'){
          cout << j+1 << " " ;
        }
      }
    }
    cout << endl;
  }
}