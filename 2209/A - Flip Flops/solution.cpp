#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        long long n, c, k;
        cin >> n >> c >> k;
        vector<long long> ar(n);
        for(auto &x : ar) cin >> x;
        sort(ar.begin(), ar.end());
        
        for(int i = 0; i < n; i++){
            if(ar[i] <= c){
                long long flips = min(k, c - ar[i]); 
                c += ar[i] + flips;
                k -= flips;
            } else break;
        }
        cout << c << "
";
    }
}