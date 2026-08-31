/*
 * Author : Kamalesh Choudhary
 * Date   : 31-08-2026
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
    bool ab = false,ba = false;
    i32 i = 0;
    while(i<n){
        if(!ab && s[i] == 'A' && i+1<n && s[i+1] == 'B'){
            ab = true;
            i++;
        }
        else if(ab && s[i] == 'B' && i+1<n && s[i+1] == 'A'){
            ba = true;
            i++;
        }
        i++;
    }
    if((ab && !ba) || (!ab && ba)){
        ab = false;
        ba = false;
        i = 0;
        while(i<n){
            if(!ba && s[i] == 'B' && i+1<n && s[i+1] == 'A'){
                ba = true;
                i++;
            }
            else if(ba && s[i] == 'A' && i+1<n && s[i+1] == 'B'){
                ab = true;
                i++;
            }
            i++;
        }
    }
    if(ab && ba )cout << "YES" << endl;
    else cout << "NO" << endl;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    solve();
 
    return 0;
}