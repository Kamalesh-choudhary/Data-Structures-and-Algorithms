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
const i32 NINF = -1'000'000'000;
const i64 LINF = 4'000'000'000'000'000'000LL;
 
int fn(int i,int x,int y,int z,vi& a,vi& b,vi& c,vector<vector<vector<vector<int>>>>& dp){
    if(x && y && z){
        return 0;
    }
 
    if(i==a.size()) return 0;
    if(dp[i][x][y][z] != -1) return dp[i][x][y][z];
    int not_pick = fn(i+1,x,y,z,a,b,c,dp);
    int picka = NINF,pickb=NINF,pickc=NINF;
    if(x == false){
        picka = a[i] + fn(i+1,!x,y,z,a,b,c,dp);
    }
    if(y == false){
        pickb= b[i] + fn(i+1,x,!y,z,a,b,c,dp);
    }
    if(z == false){
        pickc = c[i] + fn(i+1,x,y,!z,a,b,c,dp);
    }
    return dp[i][x][y][z] = max({picka,pickb,pickc,not_pick});
} 
 
void solve() {
    i32 n;
    cin >> n;
    vi a(n);
    for(auto & x:a) cin >> x;
    vi b(n);
    for(auto &x:b) cin >> x;
    vi c(n);
    for(auto &x:c) cin >> x;
 
    vector<vector<vector<vector<int>>>> dp(n+1,vector<vector<vector<int>>>(2,vector<vector<int>>(2,vector<int>(2,-1))));
 
    cout << fn(0,0,0,0,a,b,c,dp) << endl;
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