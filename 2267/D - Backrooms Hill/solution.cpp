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
  vi ar;
 
  void solve() {
    cin >> n;
    ar.resize(n);
 
    unordered_map<int, int> parity;
 
    for (int i = 0; i < n; i++) {
      cin >> ar[i];
      parity[ar[i]] = i & 1;
    }
 
    sort(ar.begin(), ar.end());
 
    int l = 0, r = n - 1;
 
    for (int value : ar) {
      int needed = parity[value];
 
      if ((l & 1) == needed)
        l++;
      else if ((r & 1) == needed)
        r--;
      else {
        cout << "NO
";
        return;
      }
    }
 
    cout << "YES
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