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
  i64 m, k;
  vector<pair<i64, i64>> intervals;
  vector<i64> prefixInfected;
 
  i64 infectedUpto(i64 x) {
    int fullyCovered = partition_point(intervals.begin(), intervals.end(),
                                       [&](const pair<i64, i64> &iv) {
                                         return iv.second <= x;
                                       }) -
                       intervals.begin();
    i64 total = prefixInfected[fullyCovered];
    if (fullyCovered < n && intervals[fullyCovered].first <= x) {
      total += x - intervals[fullyCovered].first + 1;
    }
    return total;
  }
 
  i64 infectedPeopleFrom(i64 start) {
    return infectedUpto(start + m - 1) - infectedUpto(start - 1);
  }
 
  void solve() {
    cin >> n >> m >> k;
    intervals.assign(n, {0, 0});
    prefixInfected.assign(n + 1, 0);
    for (int i = 0; i < n; i++) {
      cin >> intervals[i].first >> intervals[i].second;
      prefixInfected[i + 1] =
          prefixInfected[i] + (intervals[i].second - intervals[i].first + 1);
    }
 
    if (k == 0) {
      cout << intervals.back().second + 1 << "
";
      return;
    }
 
    i64 maxInfected = -1, bestStart = 1;
    for (const auto &[left, right] : intervals) {
      for (i64 start : {left, right - m + 1}) {
        start = max<i64>(start, 1);
        i64 infected = infectedPeopleFrom(start);
        if (infected > maxInfected) {
          maxInfected = infected;
          bestStart = start;
        }
      }
    }
 
    if (maxInfected < k) {
      cout << -1 << "
";
      return;
    }
 
    i64 lo = bestStart;
    i64 hi = intervals.back().second + 1;
    while (hi - lo > 1) {
      i64 mid = lo + (hi - lo) / 2;
      if (infectedPeopleFrom(mid) >= k)
        lo = mid;
      else
        hi = mid;
    }
    cout << lo << "
";
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