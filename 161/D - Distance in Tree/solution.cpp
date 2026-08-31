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
 
const int MAXN = 50005;
const int MAXK = 505;
 
vector<int> adj[MAXN];   // adjacency list: adj[u] = saare neighbors of node u
int n, k;
long long ans = 0;
 
int dp[MAXN][MAXK];
 
void dfs(int u, int parent) {
    // Node u khud apne se distance 0 par hai
    dp[u][0] = 1;
 
    // Har child v ko explore karo
    for (int v : adj[u]) {
        if (v == parent) continue;   // parent ki taraf wapas mat jao
 
        dfs(v, u);   // pehle child v ka poora subtree process karo
 
        // ---- STEP 1: Cross pairs count karo ----
        // Ek node "u ke ab tak merge hue part" me hai (distance d1 se u tak)
        // Doosra node "v ke subtree" me hai (distance d2 se v tak, matlab d2+1 se u tak)
        // Total distance = k chahiye => d1 + (d2+1) = k => d1 = k - d2 - 1
        for (int d2 = 0; d2 < k; d2++) {
            int d1 = k - d2 - 1;
            ans += (long long) dp[u][d1] * dp[v][d2];
        }
 
        // ---- STEP 2: Child v ka dp, parent u me merge karo ----
        // v se distance d2 par jo nodes hain, woh u se distance (d2+1) par honge
        for (int d2 = 0; d2 < k; d2++) {
            dp[u][d2 + 1] += dp[v][d2];
        }
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cin >> n >> k;
 
    for (int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
 
    dfs(1, 0);   // root = node 1, uska koi parent nahi (0 use kiya hai dummy ke liye)
 
    cout << ans << endl;
}