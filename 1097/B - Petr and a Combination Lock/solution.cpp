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
 
bool fn(i32 i,i32 sum,vi& ar){
    if(i==ar.size()){
        if(sum == 0) return true;
        else return false;
    }
    bool clock_wise = false;
    bool anti_clock_wise = false;
    clock_wise = fn(i+1,(sum+ar[i])%360,ar);
    anti_clock_wise = (sum-ar[i]<0? fn(i+1,(sum-ar[i]+360)%360,ar):fn(i+1,sum-ar[i],ar));
    return clock_wise || anti_clock_wise;
}
 
void solve() {
    i32 n;
    cin >> n;
    vi ar(n);
    for(auto &x:ar) cin >> x;
 
    cout << (fn(0,0,ar)?"YES":"NO") << endl;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    solve();
 
    return 0;
}