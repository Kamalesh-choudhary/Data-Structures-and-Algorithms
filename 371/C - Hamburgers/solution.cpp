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
  string recipe;
  i32 nb, ns, nc, pb, ps, pc;
  i64 r;
  unordered_map<char, i32> ingredient;
 
  bool can(i64 x) {
    i64 needB = ingredient['B'] * x;
    i64 needS = ingredient['S'] * x;
    i64 needC = ingredient['C'] * x;
    i64 cost = 0;
    if (needB > nb) {
      cost += (needB - nb) * pb;
    }
    if (needS > ns) {
      cost += (needS - ns) * ps;
    }
    if (needC > nc) {
      cost += (needC - nc) * pc;
    }
    return cost <= r;
  }
  void solve() {
    cin >> recipe;
    cin >> nb >> ns >> nc;
    cin >> pb >> ps >> pc;
    cin >> r;
    ingredient.clear();
    for (auto i : recipe) {
      ingredient[i]++;
    }
 
    i64 lo = 0;
    i64 hi = 1e13;
    while (lo <= hi) {
      i64 mid = lo + (hi - lo) / 2;
      if (can(mid)) {
        lo = mid + 1;
      } else {
        hi = mid - 1;
      }
    }
 
    cout << hi << endl;
  }
};
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
 
  Solution sol;
 
  sol.solve();
 
  return 0;
}