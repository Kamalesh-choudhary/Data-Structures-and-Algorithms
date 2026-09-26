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
const i64 NEG = -(1LL << 60);
 
class Solution {
public:
  i32 n, k;
  vector<vector<vector<i64>>> dp;
 
  i64 maxim_amount(i32 power, i32 day, i32 selection) {
    if (day == 0)
      return selection == k ? 0 : NEG;
 
    if (selection == k)
      return 0;
 
    if (dp[day][selection][power] != -1)
      return dp[day][selection][power];
 
    // Don't withdraw
    i64 not_pick = maxim_amount(power + 1, day - 1, selection);
 
    // Withdraw
    i64 pick = (1LL << power) + maxim_amount(1, day - 1, selection + 1);
 
    return dp[day][selection][power] = max(pick, not_pick);
  }
 
  void solve() {
    cin >> n >> k;
    dp.assign(n + 1, vector<vector<i64>>(k + 1, vector<i64>(n + 1, -1)));
 
    cout << maxim_amount(1, n, 0) << '
';
  }
};
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
 
  Solution sol;
 
  i32 t;
  cin >> t;
 
  while (t--) {
    sol.solve();
  }
 
  return 0;
}