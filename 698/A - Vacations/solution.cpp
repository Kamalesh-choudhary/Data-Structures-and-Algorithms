/*
 * Author : Kamalesh Choudhary
 * Date   : 01-09-2026
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
 
i32 fn(i32 i,i32 prev,vi& ar,vector<vector<int>>& dp){
    if(i==ar.size()) return 0;
    if(dp[i][prev] != -1) return dp[i][prev];
    i32 ans = 1 + fn(i+1,0,ar,dp);
    if((ar[i] == 1 || ar[i] == 3)&& prev != 1){
        ans = min(ans,fn(i+1,1,ar,dp));
    }
    if((ar[i] == 2 || ar[i] == 3) && prev != 2){
        ans = min(ans,fn(i+1,2,ar,dp));
    }
    return dp[i][prev] = ans;
}
 
void solve() {
    i32 n;
    cin >> n;
    vi ar(n);
    for(auto &x:ar) cin >> x;
    vector<vector<int>> dp(n,vector<int>(4,-1));
    cout << fn(0,0,ar,dp) << endl;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    solve();
     
    return 0;
}
