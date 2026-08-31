#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
 
const int MOD = 998244353;
 
ll modpow(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int T;
    cin >> T;
 
    while (T--) {
        ll n, m, r, c;
        cin >> n >> m >> r >> c;
 
        ll R = min(n, r - 1);
        ll C = min(m, c - 1);
 
        ll free = R * m + C * n - R * C;
 
        cout << modpow(2, free) << '
';
    }
}