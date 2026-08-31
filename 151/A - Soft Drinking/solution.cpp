#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int n,k,l,c,d,p,nl,np;
  cin >> n >> k >> l >> c >> d >> p >> nl >> np;
  int total_liters = k*l;
  int total_slices = c*d;
  int answer;
  answer = min((total_liters/nl),min(total_slices,(p/np)));
  cout << answer/n << endl;
}