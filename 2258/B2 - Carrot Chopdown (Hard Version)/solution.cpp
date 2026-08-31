#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
 
// --- TyPe Aliases ---
using i64 = long long;
using ull = unsigned long long;
using ld  = long double;
using Pii = pair<int, int>;
using vi  = vector<int>;
using vvi = vector<vector<int>>;
using si  = set<int>;
using mi  = map<int, int>;
 
// --- Constants ---
const int MOD  = 1e9 + 7;
const int INF  = 1e9;
const ld  PI   = acos((ld)-1);
 
// --- Macros ---
#define all(x)       (x).begin(), (x).end()
#define rall(x)      (x).rbegin(), (x).rend()
#define Pb           Push_back
#define mP           make_Pair
#define fi           first
#define se           second
#define sz(x)        (int)(x).size()
#define reP(i, a, b) for (int i = (a); i < (b); i++)
#define Per(i, a, b) for (int i = (b)-1; i >= (a); i--)
 
 
void solve() {
    int N, M;
    std::cin >> N >> M;
 
    std::vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> A[i];
    }
 
    std::vector<int> sf(M + 2);
    for (int i = 0; i < N; ++i) {
        sf[A[i]] += 1;
    }
 
    for (int i = M; i >= 1; --i) {
        sf[i - 1] += sf[i];
    }
 
    i64 sum = std::accumulate(A.begin(), A.end(), 0LL);
 
    for (int k = 1; k <= M; ++k) {
        if (k > 19) {
            cout << sum << " 
"[k==M];
            continue;
        }
        i64 cut_limit = (1LL<<k)-1;
        i64 ans = 0;
        for (int i = 1; i <= M ; ++i) {
            i64 tmp = 0;
            // I am checking this for 2^k-1 possibilities
            for (int j = 1;j<= cut_limit && j*i <= M; ++j){
                tmp += sf[i * j];
            }
            // This is the bonus i get when i get (2^k-1)+1 then i get one extra bonus
            i64 req_len_for_bonus = 1LL * (cut_limit+1)*i;
            if(req_len_for_bonus <= M) tmp += sf[req_len_for_bonus]-sf[req_len_for_bonus+1];
            ans = std::max(ans, tmp);
        }
        std::cout << ans << " 
"[k == M];
    }
    
    return;
}
 
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
 
    int TT = 1; std::cin >> TT;
    for (int i = 1; i <= TT; ++i) {
        solve();
    }
 
    return 0;
}