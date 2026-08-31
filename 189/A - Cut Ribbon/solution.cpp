#include <bits/stdc++.h>
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
const int MOD  = 1e9 + 7;
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
 
int fn(int n, int a, int b, int c,vector<int>& dp) {
    if(n == 0)
        return 0;
 
    if(n < a && n < b && n < c)
        return -1e9;
 
    if(dp[n] != -1){
        return dp[n];
    }
    int frst = -1e9;
    int scnd = -1e9;
    int thrd = -1e9;
    if(n >= a) frst = 1 + fn(n-a, a,b,c,dp);
    if(n >= b) scnd = 1 + fn(n-b, a,b,c,dp);
    if(n >= c) thrd = 1 + fn(n-c, a,b,c,dp);
    return dp[n] = max({frst, scnd, thrd});
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n,a,b,c;
    cin >> n >> a >> b >> c;
    vector<int> dp(n+1,-1);
    cout << fn(n,a,b,c,dp) << endl;
}