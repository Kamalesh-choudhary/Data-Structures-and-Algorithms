/*
 * Author : Kamalesh Choudhary
 * Date   : 01-09-2026
 */
 
#include <bits/stdc++.h>
 
#include <iostream>
 
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
  vi ar(n + 1);
  vi p(n + 1, -1);
  for (int i = 1; i <= n; i++) {
    cin >> ar[i];
    p[i] = p[i - 1];
    if (ar[i] != ar[i - 1])
      p[i] = i - 1;
  }
  i32 q;
  cin >> q;
  while (q--) {
    i32 l, r;
    cin >> l >> r;
    if (p[r] < l) {
      cout << "-1 -1" << endl;
    } else {
      cout << p[r] << " " << r << endl;
    }
  }
  cout << endl;
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