/*
 * Author : Kamalesh Choudhary
 * Date   : 02-09-2026
 */
 
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
 
void solve() {
  i32 n;
  cin >> n;
  vi coordinate(n);
  vi height(n);
  for (int i = 0; i < n; i++) {
    cin >> coordinate[i] >> height[i];
  }
 
  i32 c = min(n, 2);
  bool fellright = false;
  for (int i = 1; i < n - 1; i++) {
    i32 px = coordinate[i - 1];
    if (fellright)
      px = coordinate[i - 1] + height[i - 1];
    if (px < coordinate[i] - height[i]) {
      c++;
      fellright = false;
    } else if (coordinate[i + 1] > coordinate[i] + height[i]) {
      c++;
      fellright = true;
    } else {
      fellright = false;
    }
  }
 
  cout << c << endl;
}
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
 
  solve();
 
  return 0;
}