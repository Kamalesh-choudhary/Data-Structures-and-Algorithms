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
 
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int t;
    cin >> t;
    while(t--){
        int a,b,c;
        int ans = 0;
        cin >> a >> b >> c;
 
        if(a>b && a>c){
            int sum = b+c;
            if(sum < a){
                ans = max({b,c,sum}) - min({b,c,sum});
            }
            else{
                ans = max({a,b,c}) - min({a,b,c});
            }
        }
        else if(b>a && b>c){
            int sum = a+c;
            if(sum < b){
                ans = max({a,c,sum}) - min({a,c,sum});
            }
            else{
                ans = max({a,b,c}) - min({a,b,c});
            }
        }
        else if(c>a && c>b){
            int sum = a+b;
            if(sum < c){
                ans = max({a,b,sum}) - min({a,b,sum});
            }
            else {
                ans = max({a,b,c}) - min({a,b,c});
            }
        }
        else{
            ans = max({a,b,c}) - min({a,b,c});
        }
        cout << ans << endl;
    }
}