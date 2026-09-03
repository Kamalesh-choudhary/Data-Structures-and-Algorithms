/*
 * Author : Kamalesh Choudhary
 * Date   : 03-09-2026
 */
 
#include <bits/stdc++.h>
#include <vector>
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
  i32 n, k;
  cin >> n >> k;
 
  vector<vector<i32>> factors(n + 1);
  for (int i = 1; i <= n; i++) {       // O(n)
    for (int j = 1; j * j <= i; j++) { // O(sqrt n)
      if (i % j == 0) {
        factors[i].push_back(j);
        if (i / j != j) {
          factors[i].push_back(i / j);
        }
      }
    }
  }
 
  vector<vector<i32>> dp(k + 1, vector<i32>(n + 1, 1));
  for (int i = 2; i <= k; i++) {
    for (int j = 1; j <= n; j++) {
      dp[i][j] = 0;
      for (auto &x : factors[j]) {
        dp[i][j] = (dp[i][j] + dp[i - 1][x]) % MOD;
      }
    }
  }
 
  i32 ans = 0;
  for (int i = 1; i <= n; i++) {
    ans = (ans + dp[k][i]) % MOD;
  }
 
  cout << ans << endl;
}
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
 
  solve();
 
  return 0;
}