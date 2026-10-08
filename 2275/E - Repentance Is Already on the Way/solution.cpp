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
    int n;
    cin >> n;
    vector<i64> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
      cin >> b[i];
    }
 
    i64 same = 0;
    for (int i = 1; i < n; i++) {
      if (a[i] == b[i + 1])
        same++;
    }
 
    for (int i = 2; i <= n; i++) {
      if (a[i] == b[i - 1])
        same++;
    }
 
    if (a[n] == b[n])
      same++;
 
    i64 best = same;
    for (int k = 1; k < n; k++) {
      if (a[k] == b[k + 1])
        same--;
      if (a[k] == b[k])
        same++;
      best = max(best, same);
    }
    i64 ans = 2LL * n - 1 + best;
    cout << ans << endl;
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