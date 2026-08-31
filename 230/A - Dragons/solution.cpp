#include <bits/stdc++.h>
#include <vector>
using namespace std;
 
int main(){
 
    int s,n;
    cin >> s >> n;
    vector<pair<int,int>> path;
    for(int i=0;i<n;i++){
        int x,y;
        cin >> x >> y;
        path.push_back({x,y});
    }
    sort(path.begin(),path.end());
    bool possible = true;
    for (auto [drag,reward]:path){
        if (s>drag){
            s+= reward;
        }
        else{
            possible = false;
            break;
        }
    }
    cout << (possible?"YES":"NO") << endl;
}