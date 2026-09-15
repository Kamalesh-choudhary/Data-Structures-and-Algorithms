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
    vi ar(n);
    vi cnt(n, 0);
    for (int i = 0; i < n; i++) {
      cin >> ar[i];
    }
 
    i64 total = accumulate(ar.begin(), ar.end(), 0LL);
    if (total % 3 != 0) {
      cout << 0 << endl;
    } else {
      i64 first_half = total / 3;
      i64 curr = 0;
      for (int i = n - 1; i >= 0; i--) {
        curr += ar[i];
        if (curr == first_half) {
          cnt[i] = 1;
        }
      }
      for (int i = n - 2; i >= 0; i--) {
        cnt[i] += cnt[i + 1];
      }
 
      i64 ans = 0;
      curr = 0;
      for (int i = 0; i + 2 < n; i++) {
        curr += ar[i];
        if (curr == first_half)
          ans += cnt[i + 2];
      }
      cout << ans << endl;
    }
  }
};
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
 
  Solution sol;
 
  sol.solve();
 
  return 0;
}