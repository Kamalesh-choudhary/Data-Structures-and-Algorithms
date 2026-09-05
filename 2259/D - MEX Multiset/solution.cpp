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
  i32 n;
  cin >> n;
 
  vi a(n);
 
  i32 cnt0 = 0;
 
  for (auto &x : a) {
    cin >> x;
    if (x == 0)
      cnt0++;
  }
 
  if (cnt0 == 1) {
    cout << "NO
";
    return;
  }
 
  cout << "YES
";
 
  if (cnt0 == 0) {
    cout << string(n, 'A') << '
';
    return;
  }
 
  bool turn = false;
 
  for (auto x : a) {
    if (x == 0) {
      if (!turn) {
        cout << 'A';
        turn = true;
      } else {
        cout << 'B';
        turn = false;
      }
    } else {
      cout << 'C';
    }
  }
 
  cout << '
';
}
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
 
  i32 t;
  cin >> t;
 
  while (t--)
    solve();
 
  return 0;
}