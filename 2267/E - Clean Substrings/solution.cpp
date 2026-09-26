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
  i32 n, q;
  i64 ans, cnt0, cnt1;
  string s;
  vi prefix;
 
  void solve() {
    cin >> n >> q >> s;
 
    ans = cnt0 = cnt1 = 0;
    prefix.resize(n);
 
    // prefix[i] tells whether s[i-1] != s[i]
    for (i32 i = 1; i < n; i++) {
      prefix[i] = 0;
 
      if (s[i - 1] != s[i]) {
        prefix[i] = 1;
        ans += 1LL * i * (n - i);
      }
    }
 
    // Count zeroes and ones
    for (i32 i = 0; i < n; i++) {
      if (s[i] == '0')
        cnt0++;
      else
        cnt1++;
    }
 
    cout << (ans + cnt0 * cnt1) / 2 << ' ';
 
    for (i32 query = 1; query <= q; query++) {
      i32 pos;
      cin >> pos;
 
      // Flip the boundary between pos-1 and pos
      if (pos != 1) {
        if (prefix[pos - 1] == 0) {
          prefix[pos - 1] = 1;
          ans += 1LL * (pos - 1) * (n - pos + 1);
        } else {
          prefix[pos - 1] = 0;
          ans -= 1LL * (pos - 1) * (n - pos + 1);
        }
      }
 
      // Flip the boundary between pos and pos+1
      if (pos != n) {
        if (prefix[pos] == 0) {
          prefix[pos] = 1;
          ans += 1LL * pos * (n - pos);
        } else {
          prefix[pos] = 0;
          ans -= 1LL * pos * (n - pos);
        }
      }
 
      // Flip the actual character
      if (s[pos - 1] == '0') {
        cnt0--;
        cnt1++;
        s[pos - 1] = '1';
      } else {
        cnt1--;
        cnt0++;
        s[pos - 1] = '0';
      }
 
      cout << (ans + cnt0 * cnt1) / 2 << ' ';
    }
 
    cout << '
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