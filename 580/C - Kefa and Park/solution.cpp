#include <bits/stdc++.h>
using namespace std;
using i32 = int;
 
class Solution {
public:
  i32 n, m;
  vector<i32> ar;
  vector<vector<i32>> adj;
 
  int dfs(int v, int parent, int cnt) {
    if (cnt > m)
      return 0;
    if ((int)adj[v].size() == 1 && v != 1)
      return 1; // leaf restaurant
 
    int temp = 0;
    for (auto u : adj[v]) {
      if (u == parent)
        continue;
      int nextCnt = (ar[u] == 1) ? cnt + 1 : 0;
      temp += dfs(u, v, nextCnt);
    }
    return temp;
  }
 
  void solve() {
    cin >> n >> m;
    ar.resize(n + 1);
    for (int i = 1; i <= n; i++)
      cin >> ar[i];
 
    adj.resize(n + 1);
    for (int i = 0; i < n - 1; i++) {
      int x, y;
      cin >> x >> y;
      adj[x].push_back(y);
      adj[y].push_back(x);
    }
 
    if (n == 1) {
      cout << 1 << endl;
      return;
    }
 
    int start = (ar[1] == 1) ? 1 : 0;
    cout << dfs(1, 0, start) << endl;
  }
};
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  Solution sol;
  sol.solve();
  return 0;
}