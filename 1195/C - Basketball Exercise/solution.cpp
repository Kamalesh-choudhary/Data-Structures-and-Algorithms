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
const i64 NINF = 4'000'000'000'000'000'000LL;
 
i64 fn(int i,int prev,vi& a, vi& b,vector<vector<i64>>& dp){
    if(i==a.size()) return 0;
    if(dp[i][prev] != -1) return dp[i][prev];
    i64 not_pick = fn(i+1,prev,a,b,dp);
    i64 picka = -1e15;
    i64 pickb = -1e15;
    if(prev != 0){
        picka = a[i] + fn(i+1,0,a,b,dp);
    }
    if(prev != 1){
        pickb = b[i] + fn(i+1,1,a,b,dp);
    }
 
    return dp[i][prev] = max({picka,pickb,not_pick});
}
 
void solve() {
    i32 n;
    cin >> n;
    vi first(n),second(n);
    for(auto &x:first) cin >> x;
    for(auto &x:second) cin >> x;
    vector<vector<i64>> dp(n,vector<i64>(3,-1));
    cout << fn(0,2,first,second,dp) << endl;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    solve();
 
    return 0;
}