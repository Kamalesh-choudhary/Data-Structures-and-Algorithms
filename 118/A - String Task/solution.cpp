#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    string s;
    cin >> s;
 
    set < char > vowels = {
        'a',
        'e',
        'i',
        'o',
        'u',
        'y',
        'A',
        'E',
        'I',
        'O',
        'U',
        'Y'
    };
    string ans = "";
    for(auto &ch: s) {
        if(vowels.find(ch) == vowels.end()) {
            ans += '.';
            if(isupper(ch)) ans += (char)tolower(ch);
            else ans += ch;
        }
    }
    cout << ans << endl;
}