/*
 * Author : Kamalesh Choudhary
 * Date   : 03-09-2026
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
  vi ar(n);
  for (auto &x : ar)
    cin >> x;
  sort(all(ar));
  i64 alice = 0, bob = 0;
  bool al = true;
  for (int i = n - 1; i >= 0; i--) {
    if (al) {
      if (ar[i] % 2 == 0)
        alice += ar[i];
      al = false;
    } else {
      if (ar[i] & 1)
        bob += ar[i];
      al = true;
    }
  }
 
  if (alice == bob)
    cout << "Tie" << endl;
  if (alice > bob)
    cout << "Alice" << endl;
  if (alice < bob)
    cout << "Bob" << endl;
}
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
 
  i32 t;
  cin >> t;
 
  while (t--) {
    solve();
  }
 
  return 0;
}