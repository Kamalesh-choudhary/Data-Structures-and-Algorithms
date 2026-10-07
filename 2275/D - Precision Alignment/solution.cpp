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
  struct Lab {
    i64 sum;
    i64 cost;
    bool fixed;
  };
  void solve() {
    int n;
    i64 k;
    cin >> n >> k;
    vector<Lab> labs(n);
    i64 mn = LLONG_MAX;
    for (int i = 0; i < n; i++) {
      i64 a, b, c;
      cin >> a >> b >> c;
      i64 sum = a + b + c;
      mn = min(mn, sum);
 
      if (a > b || b > c) {
        labs[i] = {sum, 0, false};
      } else {
        if (a == b && b == c) {
          labs[i] = {sum, 0, true};
        } else {
          i64 d = min(b - a, c - b) + 1;
          labs[i] = {sum, 2 * d, false};
        }
      }
    }
    auto possible = [&](i64 target) -> bool {
      i64 needed = 0;
      for (auto &lab : labs) {
        if (lab.fixed) {
          if (lab.sum < target)
            return false;
          continue;
        }
        if (lab.sum >= target)
          continue;
        i64 cost = target - lab.sum + lab.cost;
        needed += cost;
        if (needed > k)
          return false;
      }
      return needed <= k;
    };
    i64 l = mn;
    i64 h = mn + k;
    while (l < h) {
      i64 mid = l + (h - l + 1) / 2;
      if (possible(mid)) {
        l = mid;
      } else {
        h = mid - 1;
      }
    }
 
    cout << l << endl;
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