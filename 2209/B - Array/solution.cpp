#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<long long> a(n);
        for(auto &x : a) cin >> x;
        
        for(int i = 0; i < n; i++){
            int less = 0, greater = 0;
            for(int j = i+1; j < n; j++){
                if(a[j] > a[i]) greater++;
                else if(a[j] < a[i]) less++;
            }
            cout << max(less, greater);
            if(i != n-1) cout << " ";
        }
        cout << "
";
    }
}