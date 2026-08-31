#include <bits/stdc++.h>
using namespace std;
 
int gcd(int a,int b){
    if (b==0) return a;
    return gcd(b,a%b);
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t;
    cin >> t;
    while(t--){
        int a,b;
        cin >> a >> b;
 
        int gd = gcd(a,b);
 
        int ans = 0;
        if(b%a ==0){
            ans = b/gd*b;
        }
        else{
            ans = a/gd*b;
        }
        cout << ans << endl;
    }
}