#include <bits/stdc++.h>
#include <numeric>
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
 
    vll ar(n);
    for (auto &x : ar)
      cin >> x;
 
    if (n == 1) {
      cout << 1 << endl;
      return;
    }
 
    sort(all(ar));
    i64 x = 0;
 
    for (int i = 1; i < n; i++) {
      x = gcd(x, ar[i] - ar[i - 1]);
    }
 
    if (x == 0)
      x = 1;
 
    i64 mx = ar.back();
    i64 sum = accumulate(all(ar), 0LL);
 
    i64 res = mx;
    i32 j = n - 1;
    while (true) {
      while (j >= 0 && ar[j] > res)
        j--;
      if (j < 0 || ar[j] != res)
        break;
      res -= x;
    }
 
    i64 ans = (mx * (n + 1) - (sum + res)) / x;
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