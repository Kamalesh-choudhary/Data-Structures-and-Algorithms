/*
 * Author : Kamalesh Choudhary
 * Date   : 05-09-2026
 */
 
#include <algorithm>
#include <bits/stdc++.h>
#include <unordered_map>
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
  i32 n;
  cin >> n;
  vi ar(n);
  for (auto &x : ar)
    cin >> x;
 
  i32 odd = 0;
  i32 mod4_0 = 0;
  i32 mod4_2 = 0;
  for (auto x : ar) {
    if (x & 1)
      odd++;
    else if (x % 4 == 0)
      mod4_0++;
    else
      mod4_2++;
  }
 
  cout << max({odd, mod4_0, mod4_2}) << endl;
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