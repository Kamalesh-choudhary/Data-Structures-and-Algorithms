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
 
long long fn(int n, vector<int>& ar, unordered_map<int,int>& mp, vector<long long>& dp) {
    if(n < 0)return 0;
 
    if(n == 0)return 1LL * mp[ar[n]] * ar[n];
 
    if(dp[n] != -1) return dp[n];
 
    long long sum = 1LL * mp[ar[n]] * ar[n];
    long long inc;
    if(ar[n] - ar[n-1] == 1)
        inc = sum + fn(n-2, ar, mp, dp);
    else
        inc = sum + fn(n-1, ar, mp, dp);
 
    long long exc = fn(n-1, ar, mp, dp);
    return dp[n] = max(inc, exc);
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    vector<int> ar(n);
    for(auto &x:ar) cin >> x;
 
    vector<int> uniq;
    unordered_map<int,int> mp;
    for(auto x:ar){
        if(mp.find(x) == mp.end()){
            uniq.push_back(x);
        }
        mp[x]++;
    }
 
    sort(uniq.begin(),uniq.end());
 
    int sz = uniq.size();
    vector<long long> dp(sz,-1);
    cout << fn(sz-1,uniq,mp,dp) << endl;
}