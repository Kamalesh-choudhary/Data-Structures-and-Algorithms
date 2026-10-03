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
  i32 n;
  string s;
  i64 cnt;
  void solve() {
    cin >> n;
    cin >> s;
 
    vector<i32> a;
    for (auto ch : s) {
      a.push_back((ch - '0') - 1);
    }
 
    map<i32, i32> prefix;
    prefix[0] = 1;
    i64 ans = 0;
    i32 sum = 0;
    for (int i = 0; i < n; ++i) {
      sum += a[i];
      ans += prefix[sum];
      prefix[sum]++;
    }
 
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