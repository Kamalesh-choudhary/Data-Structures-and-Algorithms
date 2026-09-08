/*
 * Author : Kamalesh Choudhary
 * Date   : 08-09-2026
 */
 
#include <algorithm>
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
  int n;
  cin >> n;
 
  string s;
  cin >> s;
 
  for (int cost = 1; cost <= 3; cost++) {
    bool dp[7] = {};
    dp[3] = true;
 
    for (char ch : s) {
      bool ndp[7] = {};
 
      for (int p = -3; p <= 3; p++) {
        if (!dp[p + 3])
          continue;
 
        for (int q = -3; q <= 3; q++) {
          if (p == q || abs(p - q) > cost)
            continue;
 
          bool ok = false;
 
          if (ch == '0')
            ok = (q == 0);
          else if (ch == '+')
            ok = (q > 0);
          else
            ok = (q < 0);
 
          if (ok)
            ndp[q + 3] = true;
        }
      }
 
      for (int i = 0; i < 7; i++)
        dp[i] = ndp[i];
    }
 
    for (int i = 0; i < 7; i++) {
      if (dp[i]) {
        cout << cost << '
';
        return;
      }
    }
  }
 
  cout << -1 << '
';
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