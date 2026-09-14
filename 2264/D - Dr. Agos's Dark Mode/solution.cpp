#include <bits/stdc++.h>
using namespace std;
 
using i32 = int;
using i64 = long long;
 
using vi = vector<i32>;
using vll = vector<i64>;
 
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
 
class Solution {
public:
  void solve() {
    int n;
    cin >> n;
 
    string s(n, '0');
 
    // Small cases
    if (n == 1) {
      s[0] = '1';
    } else if (n == 2) {
      s[1] = '1';
    } else if (n == 3) {
      s[0] = '1';
      s[2] = '1';
    } else if (n == 4) {
      s[1] = '1';
      s[3] = '1';
    } else {
      int k = n / 6;
      int r = n % 6;
 
      int p1 = 1;
      int p2, p3;
 
      if (r == 0) {
        p2 = 2 * k + 1;
        p3 = 4 * k + 1;
      } else if (r == 1 || r == 2 || r == 3) {
        p2 = 2 * k + 2;
        p3 = 4 * k + 2;
      } else {
        // r == 4 or 5
        p2 = 2 * k + 3;
        p3 = 4 * k + 5;
      }
 
      s[p1 - 1] = '1';
      s[p2 - 1] = '1';
      s[p3 - 1] = '1';
    }
 
    cout << s << '
';
  }
};
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
 
  int t;
  cin >> t;
 
  while (t--) {
    Solution sol;
    sol.solve();
  }
 
  return 0;
}