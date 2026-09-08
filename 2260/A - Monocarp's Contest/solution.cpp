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
  vi ar(n);
  for (auto &x : ar)
    cin >> x;
 
  int z = count(ar.begin(), ar.end(), 0);
  if (z <= 1) {
    cout << -1 << endl;
    return;
  }
  if (ar[0] == 0 && ar.back() == 0)
    cout << 0 << endl;
  else if (ar[0] == 0 || ar.back() == 0)
    cout << 1 << endl;
  else
    cout << 2 << endl;
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