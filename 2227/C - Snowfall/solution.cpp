#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    vector<int> ar(n);
    for(auto &x:ar) cin >> x;
    vector<int> multiple;
    vector<int> threemultiple;
    vector<int> not_multiple;
    vector<int> full;
    for(int i=0;i<n;i++){
      if(ar[i]%2 == 0){
        if (ar[i]%3 == 0){
          full.push_back(ar[i]);
        }
        else{
          multiple.push_back(ar[i]);
        }
      }
      else if (ar[i]%3 == 0){
        threemultiple.push_back(ar[i]);
      }
      else{
        not_multiple.push_back(ar[i]);
      }
    }
    for(int i=0;i<full.size();i++){
      cout << full[i] << " ";
    }
    for(int i=0;i<multiple.size();i++){
      cout << multiple[i] << " ";
    }
    for(int i=0;i<not_multiple.size();i++){
      cout << not_multiple[i] << " ";
    }
    for(int i=0;i<threemultiple.size();i++){
      cout << threemultiple[i] << " ";
    }
    cout << endl;
  }
}