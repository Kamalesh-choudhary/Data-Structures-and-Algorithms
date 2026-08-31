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
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while(t--){
        int n,m;
        cin >> n >> m;
        
        vector<int> ar(n);
        for(auto &x:ar) cin >> x;
 
        vector<int> mp(m+1);
        for(auto &x:ar) mp[x]++;
 
        vector<int> cnt(m+1);
        cnt[m] = mp[m];
        for(int i=m-1;i>=0;i--){
            cnt[i] += cnt[i+1]+mp[i];
        }
 
        int ans = 0;
        for(int i=1;i<=m;i++){
            ans = max(ans,cnt[i]+(2*i<=m?mp[2*i]:0));
        }
        cout << ans << endl;
    }
}