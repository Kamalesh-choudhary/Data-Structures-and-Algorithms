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
 
i32 fn(int i, int player, vi &ar, vector<vector<i32>> &dp) {
  if (i >= ar.size())
    return 0;
  if (dp[i][player] != -1)
    return dp[i][player];
  i32 one = INF;
  i32 two = INF;
  if (player) {
    one = fn(i + 1, 0, ar, dp);
    two = fn(i + 2, 0, ar, dp);
  } else {
    one = (ar[i] == 1) + fn(i + 1, 1, ar, dp);
    if (i + 1 < ar.size())
      two = (ar[i] == 1) + (ar[i + 1] == 1) + fn(i + 2, 1, ar, dp);
  }
  return dp[i][player] = min(one, two);
}
 
void solve() {
  i32 n;
  cin >> n;
  vi ar(n);
  for (auto &x : ar)
    cin >> x;
  vector<vector<i32>> dp(n, vector<int>(2, -1));
  cout << fn(0, 0, ar, dp) << endl;
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