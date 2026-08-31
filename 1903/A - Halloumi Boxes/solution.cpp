#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t;
    cin >> t;
    while(t--){
        int n,k ;
        cin >> n >> k;
        vector<int> ar(n);
        for(auto &x:ar)cin >> x;
        
        if(is_sorted(ar.begin(),ar.end()) || k > 1){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
}