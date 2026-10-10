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
    int h = 1;
    while (h * 2 <= n)
      h *= 2;
 
    vector<int> p;
    p.reserve(4 * h);
    for (int r = 0; r < 2; r++) {
      for (int x = 0; x < h; x++)
        p.push_back(x);
    }
    vector<int> upper{2 * h - 1};
    for (int x = h; x < 2 * h - 1; x++)
      upper.push_back(x);
    for (int r = 0; r < 2; r++) {
      for (int x : upper)
        p.push_back(x);
    }
    cout << p.size() - 1 << endl;
    for (int i = 1; i < p.size(); i++) {
      cout << (p[i] ^ p[i - 1]) << " 
"[i + 1 == p.size()];
    }
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