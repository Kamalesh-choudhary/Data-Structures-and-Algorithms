#include <bits/stdc++.h>
using i32 = int;
using i64 = long long;
 
using  namespace std;
 
void solve(){
    i32 n;
    cin >> n;
    i64 first = 1;
    i64 dist = 0;
    for(int i=2;i<=n;i++){
        i64 response;
        cout << "? 1 " << i << " " << dist+1 << endl;
        cin >> response;
        if(response == -1) return;
        if(response){
            first = i;
            dist++;
            while(response){
                cout << "? 1 " << i << " " << dist+1 << endl;
                cin >> response;
                if(response == -1 )return;
                if(response) dist++;
            }
        }
    }
 
    i64 second = 1;
    for(int i=2;i<=n;i++){
        if(i==first) continue;
        i64 response;
        cout << "? " << first << " " << i << " " << dist+1 << endl;
        cin >> response;
        if(response == -1) return ;
        if(response){
            dist++;
            second = i;
            while(response){
                cout << "? " << first << " " << i << " " << dist+1 << endl;
                cin >> response;
                if(response == -1) return ;
                if(response) dist++;
            }
        }
    }
 
    cout << "! " << first << " " << second << " " << dist << endl;
 
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    i32 t;
    cin >> t;
    while(t--){
        solve();
    }
}