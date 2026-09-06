/*
 * Author : Kamalesh Choudhary
 * Date   : 03-09-2026
 */
 
#include <bits/stdc++.h>
using namespace std;
 
using i32 = int;
using i64 = long long;
using u32 = unsigned int;
using u64 = unsigned long long;
 
using pii = pair<i32, i32>;
using pll = pair<i64, i64>;
 
using vi = vector<i32>;
using vll = vector<i64>;
 
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
 
const i32 MOD = 998244353;
const i32 INF = 1'000'000'000;
const i64 LINF = 4'000'000'000'000'000'000LL;
 
void solve() {
  string s;
  cin >> s;
 
  i64 extra = 0, ops = 0, fact = 1, res = 1;
  i32 n = s.size();
 
  for (i32 i = 0; i < n - 1; i++) {
    if (s[i] == s[i + 1])
      extra++;
    else {
      ops += extra;
      extra++;
      res = (res % MOD * extra % MOD) % MOD;
      extra = 0;
    }
  }
  if (extra != 0) {
    ops += extra;
    extra++;
    res = (res % MOD * extra % MOD) % MOD;
  }
  for (i64 i = 1; i <= ops; i++) {
    fact = ((fact % MOD) * (i % MOD)) % MOD;
  }
 
  res = ((res % MOD) * (fact % MOD)) % MOD;
  cout << ops << " " << res << endl;
}
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
 
  i32 t;
  cin >> t;
 
  while (t--) {
    solve();
  }
 
  return 0;
}