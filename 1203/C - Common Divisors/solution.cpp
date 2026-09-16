#include <algorithm>
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
 
    i64 g = 0;
 
    while (n--) {
      i64 x;
      cin >> x;
      g = gcd(g, x);
    }
 
    i64 cnt = 0;
 
    for (i64 i = 1; i * i <= g; i++) {
      if (g % i == 0) {
        cnt++;
        if (i != g / i)
          cnt++;
      }
    }
 
    cout << cnt << endl;
  }
};
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
 
  Solution sol;
 
  sol.solve();
 
  return 0;
}