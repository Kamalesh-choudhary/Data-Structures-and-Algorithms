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
 
i64 sumOfDigits(i32 x) {
  i64 total = 0;
  while (x) {
    total += x % 10;
    x /= 10;
  }
  return total;
}
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  i64 sum = 0;
  vector<i64> dp(2e5 + 7, 0);
  for (i32 i = 0; i < dp.size(); i++) {
    sum += sumOfDigits(i);
    dp[i] = sum;
  }
 
  i32 t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    cout << dp[n] << endl;
  }
}