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
 
bool fn(i64 x) {
    for(i64 cnt = 0; cnt <= 10; cnt++) {
        if(x - cnt * 111 >= 0 &&
           (x - cnt * 111) % 11 == 0)
            return true;
    }
    return false;
}
 
void solve() {
    i64 x;
    cin >> x;
 
    cout << (fn(x)?"YES":"NO") << endl;
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