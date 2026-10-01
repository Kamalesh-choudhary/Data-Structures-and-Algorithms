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
 
class Solution {
public:
  i32 n, q;
  vi a;
  vector<pair<i32, i32>> query;
  void solve() {
    cin >> n >> q;
    a.resize(n + 1);
    query.clear();
    for (i32 i = 1; i <= n; i++) {
      cin >> a[i];
    }
 
    for (int i = 0; i < q; i++) {
      i32 l, r;
      cin >> l >> r;
      query.push_back({l, r});
    }
 
    // Creating the Difference array
    vi coeff(n + 1, 0);
    for (auto [l, r] : query) {
      coeff[l] += 1;
      if (r + 1 <= n)
        coeff[r + 1] -= 1;
    }
 
    // Now creating the range
    vi pref(n + 1, 0);
    i32 sum = 0;
    for (i32 i = 1; i <= n; i++) {
      i32 x = coeff[i];
      sum += x;
      pref[i] = sum;
    }
 
    sort(all(pref));
    sort(all(a));
 
    i64 total = 0;
    for (i32 i = n; i >= 1; i--) {
      total += 1LL * pref[i] * a[i];
    }
 
    cout << total << endl;
  }
};
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
 
  Solution sol;
 
  sol.solve();
 
  return 0;
}