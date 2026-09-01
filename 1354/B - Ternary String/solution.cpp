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
 
void solve() {
    string s;
    cin >> s;
 
    i32 n = s.size();
    i32 ans = 1e9;
    i32 l=0,r=0;
    unordered_map<char,i32> mp;
    while(r<n){
        mp[s[r]]++;
        while(mp.size()==3){
            ans = min(ans,r-l+1);
            mp[s[l]]--;
            if(mp[s[l]] == 0) mp.erase(s[l]);
            l++;
        }
        r++;
    }
    cout << (ans==1e9?0:ans) << endl;
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