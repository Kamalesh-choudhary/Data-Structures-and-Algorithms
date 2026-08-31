#include <bits/stdc++.h>
using namespace std;
using ll = long long ;
using vi = vector<int>;
using vl = vector<long long>;
 
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vi ar(n);
        for(auto &x:ar)cin >> x;
        vi sorted = ar;
        sort(sorted.begin(),sorted.end());
        
        ll cnt = 0, a = 0, b = 0;
        for(int i=0;i<n;i++){
            a += ar[i];
            b += sorted[i];
            cnt += a-b;
        }
        
        map<ll,ll> hmap;
        for(ll i=0;i<n;i++){
            auto v = sorted[i];
            if(hmap.find(v)!=hmap.end()){
                hmap[v] = min(hmap[v],i);
            }
            else{
                hmap[v] = i;
            }
        }
        ll move = 0;
        for(int i=0;i<n;i++){
            ll v = ar[i];
            move = max(move,i-hmap[v]);
        }
        cout << cnt+move << endl;
    }
}