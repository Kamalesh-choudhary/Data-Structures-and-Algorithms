#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while(t--){
        int a,b,c,d,e,f,g;
        cin >> a >> b >> c >> d >> e >> f >> g;
        int total = a+b+c+d+e+f+g;
        int maximum = max(a,max(b,max(c,max(d,max(e,max(f,g))))));
        total -= maximum;
        cout << -total + maximum << endl;
    }
}