#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int n;
  cin >> n;
  int mishka = 0;
  int chris = 0;
  for (int i=0;i<n;i++){
    int a,b;
    cin >> a >> b;
    if (a>b){
      mishka++;
    }
    if (b>a){
      chris++;
    }
  }
  if (mishka > chris){
    cout << "Mishka" << endl;
  }
  else if (chris > mishka){
    cout << "Chris" << endl;
  }
  else{
    cout << "Friendship is magic!^^" << endl;
  }
}