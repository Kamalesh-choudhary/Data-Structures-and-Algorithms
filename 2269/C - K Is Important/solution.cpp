#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
 
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
 
template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
class Solution {
public:
  i32 n, k;
  vector<i32> a;
 
  void solve() {
    cin >> n >> k;
 
    a.resize(n);
 
    ordered_set<i32> alive;
 
    for (i32 i = 0; i < n; i++) {
      cin >> a[i];
      alive.insert(i);
    }
 
    i64 ans = 0;
 
    while ((i32)alive.size() >= k) {
      i32 m = alive.size();
 
      i32 left_pos = *alive.find_by_order(k - 1);
      i32 right_pos = *alive.find_by_order(m - k);
 
      if (a[left_pos] >= a[right_pos]) {
        ans += a[left_pos];
        alive.erase(left_pos);
      } else {
        ans += a[right_pos];
        alive.erase(right_pos);
      }
    }
 
    cout << ans << '
';
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