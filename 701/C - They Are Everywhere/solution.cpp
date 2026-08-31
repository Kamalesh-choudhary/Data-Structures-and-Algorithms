#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int n;
  cin >> n;
  std::string s;
  cin >> s;
 
  unordered_map<char,int> hashmap;
  for (char ch: s){
    hashmap[ch]++;
  }
 
  int unique = hashmap.size();
  int ans = INT_MAX;
  unordered_map<char,int> second_hmap;
  int left = 0,right = 0;
  while (right < n){
    second_hmap[s[right]]++;
    if (second_hmap.size() == unique){
      while (second_hmap.size() == unique){
        ans = std::min(ans,right-left+1);
        if (second_hmap.find(s[left]) != second_hmap.end()){
          second_hmap[s[left]]--;
        }
        if (second_hmap[s[left]] == 0){
          second_hmap.erase(s[left]);
        } 
        left++;
      }
    }
    right += 1;
  }
  cout << ans << endl;
}