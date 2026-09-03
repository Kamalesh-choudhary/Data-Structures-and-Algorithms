/*
 * Author : Kamalesh Choudhary
 * Date   : 03-09-2026
 */
 
#include <bits/stdc++.h>
#include <unordered_set>
#include <valarray>
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
  i32 n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  unordered_set<char> characters;
  for (int i = 0; i < k; i++) {
    char c;
    cin >> c;
    characters.insert(c);
  }
 
  i64 total = 0;
  i64 len = 0;
  for (char c : s) {
    if (characters.count(c)) {
      len++;
    } else {
      total += len * (len + 1) / 2;
      len = 0;
    }
  }
 
  total += len * (len + 1) / 2;
 
  cout << total << endl;
}
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
 
  solve();
 
  return 0;
}