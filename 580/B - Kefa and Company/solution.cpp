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
  i32 n, d;
  vector<pair<i32, i32>> friends;
 
  void solve() {
    cin >> n >> d;
    friends.clear();
    for (int i = 0; i < n; i++) {
      i32 money, frnd_fac;
      cin >> money >> frnd_fac;
      friends.push_back({frnd_fac, money});
    }
 
    sort(all(friends), [](auto &a, auto &b) { return a.second < b.second; });
 
    i64 ans = 0;
    i64 friend_factor = 0;
    i32 l = 0, r = 0;
    while (r < n) {
      friend_factor += friends[r].first;
      while (friends[r].second - friends[l].second >= d) {
        friend_factor -= friends[l].first;
        l++;
      }
      ans = max(ans, friend_factor);
      r++;
    }
 
    cout << ans << endl;
  }
};
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
 
  Solution sol;
 
  sol.solve();
 
  return 0;
}