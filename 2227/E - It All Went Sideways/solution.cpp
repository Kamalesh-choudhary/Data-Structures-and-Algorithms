#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vint = vector<int>;
using vlng = vector<long long>;
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vlng ar(n);
        for(auto &x:ar)cin >> x;
        ll cnt = 0;
        ll mn = LLONG_MAX;
        map<ll,ll> hmap;
        for(int i=n-1;i>=0;i--){
            mn = min(mn,ar[i]);
            cnt += ar[i]-mn;
            hmap[mn]++;
        }
        ll maxmove = 0;
        for(auto &x:hmap){
            maxmove = max(maxmove,x.second-1);
        }
        cout << cnt+maxmove << endl;
    }
}