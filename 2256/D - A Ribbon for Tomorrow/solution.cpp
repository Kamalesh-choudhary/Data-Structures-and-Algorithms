#include <bits/stdc++.h>
#include <functional>
using namespace std;
 
// --- Type Aliases ---
using ll  = long long;
using ull = unsigned long long;
using ld  = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi  = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vvll= vector<vector<ll>>;
using si  = set<int>;
using mi  = map<int, int>;
 
// --- Constants ---
const int INF  = 1e9;
const ll  LINF = 1e18;
const ld  PI   = acos((ld)-1);
 
// --- Macros ---
#define all(x)       (x).begin(), (x).end()
#define rall(x)      (x).rbegin(), (x).rend()
#define pb           push_back
#define mp           make_pair
#define fi           first
#define se           second
#define sz(x)        (int)(x).size()
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define per(i, a, b) for (int i = (b)-1; i >= (a); i--)
 
// --- Debug ---
#ifdef DEBUG
#define dbg(x) cerr << #x << " = " << x << "
"
#else
#define dbg(x)
#endif
 
const ll MOD = 998244353;
const ll MAXN = 1000000;
 
ll fact[MAXN+1],invfac[MAXN+1];
 
ll power(ll a, ll b){
    ll res = 1;
    while(b){
        if(b&1) res = res*a%MOD;
        a = a*a%MOD;
        b >>= 1;     
    }
    return res;
}
 
ll C(int n,int r){
    if(r<0 || r>n){
        return 0;
    }
    return fact[n]*invfac[r]%MOD*invfac[n-r]%MOD;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    fact[0] = 1;
    for(int i=1;i<=MAXN;i++){
        fact[i] = fact[i-1]*i%MOD;
    }
    invfac[MAXN] = power(fact[MAXN],MOD-2);
    for(int i=MAXN;i>=1;i--){
        invfac[i-1] = invfac[i]*i%MOD;
    }
    
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;
 
        int zero = 0;
        int one = 0;
        int transition = 0;
        for(char c:s){
            if(c=='0')zero++;
            else one++;
        }
        for(int i=1;i<n;i++){
            if(s[i] != s[i-1]) transition++;
        }
 
        if(transition==0){
            cout << 1 << endl;
            continue;
        }
        int runs = transition+1;
        int zerorun,onerun;
        if(s[0] == '0'){
            zerorun = (runs+1)/2;
            onerun = runs/2;
        }
        else{
            onerun = (runs+1)/2;
            zerorun = runs/2;
        }
        ll ans = C(zero-1,zerorun-1)*C(one-1,onerun-1)%MOD;
        cout << ans << endl;
        
    }
}