#include <bits/stdc++.h>
using namespace std;
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string s;
    cin >> s;
    string hello = "hello";
    int n = s.size();
    int x = 0;
    for(int i=0;i<n;i++){
        if (hello[x] == s[i]){
            x++;
        }
    }
    if (x == 5) cout << "YES" << endl;
    else cout << "NO" << endl;
}