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
    
    int n;
    cin >> n;
    vector<int> boys(n);
    for(auto &x:boys) cin >> x;
 
    int m;
    cin >> m;
    vector<int> girls(m);
    for(auto &x:girls) cin >> x;
 
    sort(boys.begin(),boys.end());
    sort(girls.begin(),girls.end());
 
    int x = 0;
    int y = 0;
    int pair = 0;
    while(x<n && y<m){
        int diff = abs(boys[x] - girls[y]);
        if(diff <= 1){
            x++;
            y++;
            pair++;
        }
        else{
            if(boys[x] < girls[y]){
                x++;
            }
            else{
                y++;
            }
        }
    }
    cout << pair << endl;
}