#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main(){
    int t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        n = 2*n;
        vector<ll> ar(n);
        for(auto &x:ar)cin >> x;
        vector<ll> zeroidx;
        int ans = INT_MIN;
        for(int i=0;i<n;i++){
            if (ar[i]==0){
                zeroidx.push_back(i);
            }
        }
        
        auto findmax = [&](ll left,ll right)->void{
            ll x=left,y=right;
            for (;x<y;x++,y--){
                if(ar[x]!=ar[y]){
                    return;
                }
            }
            ll l = left;
            ll r = right;
            while (l>0 && r+1<n && ar[l-1] == ar[r+1]){
                l--;
                r++;
            }
            set<int> curr;
            for(int i=l;i<=r;i++){
                curr.insert(ar[i]);
            }
            int temp = 0;
            while(curr.find(temp) != curr.end()){
                temp++;
            }
            ans = max(ans,temp);
        };
        findmax(zeroidx[0],zeroidx[0]);
        findmax(zeroidx[1],zeroidx[1]);
        findmax(zeroidx[0],zeroidx[1]);
        cout << ans << endl;
    }
}