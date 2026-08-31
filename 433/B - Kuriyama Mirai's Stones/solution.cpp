#include <atomic>
#include <bits/stdc++.h>
#include <vector>
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
    vll unordered(n);
    vll ordered(n);
    for(int i=0;i<n;i++){
        ll x;
        cin >> x;
        unordered[i] = x;
        ordered[i] = x;
    }
    sort(ordered.begin(),ordered.end());
    vector<ll> unordered_pref(n+1,0);
    vector<ll> ordered_pref(n+1,0);
    for(int i=1;i<=n;i++){
        unordered_pref[i] = unordered_pref[i-1] + unordered[i-1];
        ordered_pref[i] = ordered_pref[i-1] + ordered[i-1];
    }
    int m;
    cin >> m;
    while(m--){
        int type,l,r;
        cin >> type >> l >> r;
        if(type == 1){
            cout << unordered_pref[r] - unordered_pref[l-1] << endl;
        }
        else{
            cout << ordered_pref[r] - ordered_pref[l-1] << endl;
        }
    }
}