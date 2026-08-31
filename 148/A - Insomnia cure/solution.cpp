#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int k,l,m,n,d;
  cin >> k;
  cin >> l;
  cin >> m;
  cin >> n;
  cin >> d;
  int k_dragons = floor(d/k);
  int l_dragons = floor(d/l);
  int m_dragons = floor(d/m);
  int n_dragons = floor(d/n);
  int kl_dragons = floor(d/lcm(k,l));
  int lm_dragons = floor(d/lcm(l,m));
  int km_dragons = floor(d/lcm(k,m));
  int mn_dragons = floor(d/lcm(m,n));
  int ln_dragons = floor(d/lcm(l,n));
  int kn_dragons = floor(d/lcm(k,n));
  int klm_dragons = floor(d/lcm(k,lcm(l,m)));
  int kln_dragons = floor(d/lcm(k,lcm(l,n)));
  int lmn_dragons = floor(d/lcm(l,lcm(m,n)));
  int kmn_dragons = floor(d/lcm(k,lcm(m,n)));
  int klmn_dragons = floor(d/lcm(k,lcm(l,lcm(m,n))));
  int answer = (k_dragons+l_dragons+m_dragons+n_dragons)-(kl_dragons+km_dragons+kn_dragons+lm_dragons+ln_dragons+mn_dragons)+(klm_dragons+kln_dragons+lmn_dragons+kmn_dragons)-(klmn_dragons);
  cout << answer << endl;
}