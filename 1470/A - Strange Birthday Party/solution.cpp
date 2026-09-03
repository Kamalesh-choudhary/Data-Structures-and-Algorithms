/*
 * Author : Kamalesh Choudhary
 * Date   : 03-09-2026
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
  i32 n, m;
  cin >> n >> m;
  vi friends(n + 1);
  vi presents(m + 1);
  for (int i = 1; i <= n; i++) {
    cin >> friends[i];
  }
  for (int i = 1; i <= m; i++) {
    cin >> presents[i];
  }
 
  sort(all(friends));
  i64 cost = 0;
  i32 j = 1;
  for (int i = n; i >= 1; i--) {
    i32 k = friends[i];
    if (j <= k) {
      cost += presents[j];
      j++;
    } else {
      cost += presents[k];
    }
  }
 
  cout << cost << endl;
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