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
    vector<i64> ar(n + 1);
    for (int i = 1; i <= n; i++)
      cin >> ar[i];
 
    vector<long long> val(n + 1);
    for (int i = 1; i <= n - 4; i++) {
      val[i] = ar[i] + ar[i + 2] - ar[i + 4];
    }
 
    unordered_map<i64, i64> freq;
    i64 ans = 0;
    for (int i = 1; i <= n - 4; i++) {
      ans += freq[val[i]];
      if (i - 2 >= 1 && val[i - 2] == val[i])
        ans--;
      if (i - 4 >= 1 && val[i - 4] == val[i])
        ans--;
      freq[val[i]]++;
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