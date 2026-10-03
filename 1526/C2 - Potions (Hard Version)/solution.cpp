#include <bits/stdc++.h>
#include <queue>
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
  i64 health;
 
  void solve() {
    cin >> n;
    ar.resize(n);
    for (auto &x : ar)
      cin >> x;
    health = 0;
    priority_queue<i32, vector<i32>, greater<i32>> pq;
    i32 cnt = 0;
    for (auto x : ar) {
      health += x;
      cnt++;
 
      if (x < 0) {
        pq.push(x);
      }
      if (health < 0) {
        i32 mini = pq.top();
        pq.pop();
 
        health -= mini;
        cnt--;
      }
    }
    cout << cnt << endl;
  }
};
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
 
  Solution sol;
 
  sol.solve();
 
  return 0;
}