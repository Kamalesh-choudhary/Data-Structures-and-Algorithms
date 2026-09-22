#include <bits/stdc++.h>
using namespace std;
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    int xsum= 0,ysum = 0,zsum = 0;
    for(int i=0;i<n;i++){
        int x,y,z;
        cin >> x >> y >> z;
        xsum += x;
        ysum += y;
        zsum += z;
    }
    if(xsum == 0 && ysum == 0 && zsum == 0){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
}