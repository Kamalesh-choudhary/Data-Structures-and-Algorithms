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
 
string fn(i32 i, string &s, string curr) {
  if (curr.size() == 3) {
    return stoi(curr) % 8 == 0 ? curr : "";
  }
  if (i == s.size()) {
    if (!curr.empty() && stoi(curr) % 8 == 0)
      return curr;
    return "";
  }
  string not_pick = fn(i + 1, s, curr);
  string pick = fn(i + 1, s, curr + s[i]);
  if (!pick.empty())
    return pick;
  return not_pick;
}
 
void solve() {
  string n;
  cin >> n;
  string ans = fn(0, n, "");
  if (ans.empty())
    cout << "NO" << endl;
  else {
    cout << "YES" << endl << stoi(ans) << endl;
  }
}
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
 
  solve();
 
  return 0;
}