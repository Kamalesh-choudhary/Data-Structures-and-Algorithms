#include <bits/stdc++.h>
using namespace std;
 
int main() {
    string s;
    cin >> s;
 
    bool all_upper_from_1 = all_of(s.begin()+1, s.end(), [](char c){ return isupper(c); });
 
    if (all_upper_from_1) {
        for(auto &ch : s) {
            if(islower(ch)) ch = toupper(ch);
            else ch = tolower(ch);
        }
    }
    cout << s << endl;
}