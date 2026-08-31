#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int n;
  cin >> n;
  int ans = 0;
  vector<string> strings(n);
  for (int i=0;i<n;i++){
    string temp;
    cin >> temp;
    if (temp == "Tetrahedron") ans += 4;
    if (temp == "Cube") ans += 6;
    if (temp == "Octahedron") ans += 8;
    if (temp == "Dodecahedron") ans += 12;
    if (temp == "Icosahedron") ans += 20;
    strings[i] = temp;
  }
  cout << ans << endl;
}