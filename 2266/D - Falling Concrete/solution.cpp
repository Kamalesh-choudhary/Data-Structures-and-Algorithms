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
  void solve() {
    i32 n;
    cin >> n;
    i32 ballast = 0;
    vector<i64> c(n);
    for (int k = 1; k <= n; k++) {
      i64 a;
      cin >> a;
      c[k - 1] = a - k;
    }
    sort(c.begin(), c.end());
    c.erase(unique(c.begin(), c.end()), c.end());
 
    i32 best = 0, run = 0;
    for (size_t i = 0; i < c.size(); i++) {
      if (i > 0 && c[i] == c[i - 1] + 1)
        run++;
      else
        run = 1;
      best = max(best, run);
    }
    cout << best << "
";
  }
};
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
 
  Solution sol;
 
  i32 t;
  cin >> t;
 
  while (t--) {
    sol.solve();
  }
 
  return 0;
}