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
  static const int T = 100;
  int digitSquareSum(int x) {
    int sum = 0;
 
    while (x > 0) {
      int d = x % 10;
      sum += d * d;
      x /= 10;
    }
 
    return sum;
  }
 
  int advance(int x) {
    for (int k = 0; k < T; k++) {
      x = digitSquareSum(x);
    }
 
    return x;
  }
 
  void solve() {
    int n;
    cin >> n;
 
    unordered_map<int, i64> freq;
    freq.reserve(n * 2);
 
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
 
      freq[advance(x)]++;
    }
 
    i64 ans = 0;
    for (auto &p : freq) {
      i64 c = p.second;
      ans += c * (c - 1) / 2;
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