#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<ll> ar(n);
        for(auto &x : ar) cin >> x;
        ll maxVal = *max_element(ar.begin(), ar.end());
        multiset<ll> available(ar.begin(), ar.end());
        vector<ll> arranged;
        arranged.push_back(maxVal);
        available.erase(available.find(maxVal));
        ll mex = 0;
        while(available.count(mex)){
            arranged.push_back(mex);
            available.erase(available.find(mex));
            mex++;
        }
        for(auto x : available) arranged.push_back(x);
        ll total = 0, curMax = 0, curMex = 0;
        multiset<ll> seen;
        for(int i = 0; i < n; i++){
            seen.insert(arranged[i]);
            curMax = max(curMax, arranged[i]);
            while(seen.count(curMex)) curMex++;
            total += curMex + curMax;
        }
        cout << total << "
";
    }
}