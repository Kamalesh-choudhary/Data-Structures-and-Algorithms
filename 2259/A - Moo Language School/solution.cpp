/*
 * Author : Kamalesh Choudhary
 * Date   : 05-09-2026
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
  i32 n, k;
  cin >> n >> k;
  string s;
  cin >> s;
 
  i32 ans = 0;
  for (int i = 0; i < n; i += k) {
    bool all_one = true;
    for (int j = i; j < i + k; j++) {
      if (s[j] == '0') {
        all_one = false;
        break;
      }
    }
    if (all_one)
      ans++;
  }
 
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