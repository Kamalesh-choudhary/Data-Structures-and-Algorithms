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
 
bool possible(int mid,ll n,ll k){
    int q = mid/k;
    int r = mid%k;
 
    ll cost = 0;
    if(q>=61) return false;
 
    cost += (k-r)*((1LL<<q)-1);
    if(q+1 >= 61){
        if(r>0) return false;
    }
    else{
        cost += r*((1LL<<(q+1))-1);
    }
    return cost <= n;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while(t--){
        ll n,k;
        cin >> n >> k;
 
        int ans = 0;
        int low = 0;
        int high = 60*k;
        while(low<= high){
            int mid = (low+high)/2;
            if(possible(mid,n,k)){
                ans = mid;
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        cout << ans << endl;
    }
}