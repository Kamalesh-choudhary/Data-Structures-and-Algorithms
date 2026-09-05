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
 
  vi ar(n);
  for (auto &x : ar)
    cin >> x;
 
  i32 first = -1, last = -1;
  for (i32 i = 0; i < n; i++) {
    if (ar[i] != 0) {
      if (first == -1)
        first = i;
      last = i;
    }
  }
 
  if (first == -1) {
  } else {
    for (i32 i = first + 1; i < last; i++) {
      if (ar[i] == -1)
        ar[i] = 0;
    }
    ar[first] = 1;
    ar[last] = 1;
  }
 
  for (auto x : ar)
    cout << x << ' ';
 
  cout << '
';
}
 
int main() {
  i32 t;
  cin >> t;
  while (t--) {
    solve();
  }
}