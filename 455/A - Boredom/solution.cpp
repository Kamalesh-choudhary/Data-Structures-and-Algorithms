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
  int n;
  vi ar, uniq;
  unordered_map<int, int> mp;
  long long fn(int n, vector<int> &ar, unordered_map<int, int> &mp,
               vector<long long> &dp) {
    if (n < 0)
      return 0;
    if (n == 0)
      return 1LL * mp[ar[n]] * ar[n];
    if (dp[n] != -1)
      return dp[n];
    long long sum = 1LL * mp[ar[n]] * ar[n];
    long long inc;
    if (ar[n] - ar[n - 1] == 1)
      inc = sum + fn(n - 2, ar, mp, dp);
    else
      inc = sum + fn(n - 1, ar, mp, dp);
    long long exc = fn(n - 1, ar, mp, dp);
    return dp[n] = max(inc, exc);
  }
  void solve() {
    cin >> n;
    ar.resize(n);
    mp.clear();
    uniq.clear();
    for (auto &x : ar) {
      cin >> x;
    }
    for (auto x : ar) {
      if (mp.find(x) == mp.end()) {
        uniq.push_back(x);
      }
      mp[x]++;
    }
 
    sort(all(uniq));
    int sz = uniq.size();
 
    vector<i64> dp(sz, -1);
    cout << fn(sz - 1, uniq, mp, dp) << endl;
  }
};
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
 
  Solution sol;
 
  sol.solve();
 
  return 0;
}