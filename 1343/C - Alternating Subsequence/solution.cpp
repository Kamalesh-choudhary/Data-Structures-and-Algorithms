/*
 * Author : Kamalesh Choudhary
 * Date   : 31-08-2026
 */
 
#include <bits/stdc++.h>
#include <utility>
#include <vector>
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
 
const i32 MOD = 1e9+7;
const i32 INF = 1e9;
const i64 LINF = 1e17;
const i64 NINF = -1e17;
 
pair<i64,i64> fn(i64 i,int prev,vi& ar,vector<vector<pair<i64,i64>>>& dp){
    if(i==ar.size()) return {0,0};
    if(dp[i][prev] != make_pair(-1LL,-1LL)) return dp[i][prev];
    pair<i64,i64> not_pick = fn(i+1,prev,ar,dp);
    pair<i64,i64> pick = {-1,NINF};
    if(prev==0 && ar[i]>0){
        auto next = fn(i + 1, 1, ar, dp);
        pick = {next.first + 1, next.second + ar[i]};
    }
    else if(prev==1 && ar[i]<0){
        auto next = fn(i + 1, 0, ar, dp);
        pick = {next.first + 1, next.second + ar[i]};
    }
    // Compare: length first, sum second
    if (pick.first > not_pick.first)
        return dp[i][prev] = pick;
 
    if (pick.first < not_pick.first)
        return dp[i][prev] = not_pick;
 
    // Same length -> maximize sum
    return dp[i][prev] = max(pick, not_pick);
}
 
void solve() {
    i32 n;
    cin >> n;
    vi ar(n);
    for(auto &x:ar) cin >> x;
    vector<vector<pair<i64,i64>>> dp(n,vector<pair<i64,i64>>(2,{-1,-1}));
    auto ans1 = fn(0, 0, ar, dp);
    auto ans2 = fn(0, 1, ar, dp);
    
    auto ans = max(ans1, ans2);
    cout << ans.second << '
';
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