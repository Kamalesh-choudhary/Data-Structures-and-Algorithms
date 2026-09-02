/*
 * Author : Kamalesh Choudhary
 * Date   : 02-09-2026
 */
 
#include <bits/stdc++.h>
#include <numeric>
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
 
i64 maxim_sum(vi &ar, i32 start, i32 end) {
  i64 total = ar[start];
  i64 ans = ar[start];
  for (int i = start + 1; i < end; i++) {
    total = max(total + ar[i], (i64)ar[i]);
    ans = max(ans, total);
  }
  return ans;
}
 
void solve() {
  i32 n;
  cin >> n;
  vi ar(n);
  for (auto &x : ar)
    cin >> x;
 
  i64 total = accumulate(ar.begin(), ar.end(), 0LL);
  i64 maxi_left, maxi_right;
  maxi_left = maxim_sum(ar, 0, n - 1);
  maxi_right = maxim_sum(ar, 1, n);
  i64 maxi = max(maxi_left, maxi_right);
  cout << (total > maxi ? "YES" : "NO") << endl;
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