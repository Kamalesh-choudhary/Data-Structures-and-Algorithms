/*
 * Author : Kamalesh Choudhary
 * Date   : 08-09-2026
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
 
const i32 MOD = 1'000'000'007;
const i32 INF = 1'000'000'000;
const i64 LINF = 4'000'000'000'000'000'000LL;
 
void solve() {
  i64 x, y, k;
  cin >> x >> y >> k;
 
  int d = y - x;
  if (d == 0) {
    cout << 0 << endl;
    return;
  }
  i64 cnt = max(0LL, min(k, d - x + 1));
  i64 ans = 0;
  for (i64 i = 0; i < cnt; i++) {
    ans += d % (x + i);
  }
  ans += (k - cnt) * d;
  cout << ans << endl;
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