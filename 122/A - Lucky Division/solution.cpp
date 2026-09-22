#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int n;
    cin >> n;
    bool ans = false;
    vector < int > lucky = {
        4,
        7,
        44,
        47,
        74,
        77,
        444,
        447,
        474,
        477,
        744,
        747,
        774,
        777
    };
    for(int i = 0; i < lucky.size(); i++) {
        if (n%lucky[i] == 0) {
            ans = true;
            break;
        }
    }
    if (ans) cout << "YES" << endl;
    else cout << "NO" << endl;
}