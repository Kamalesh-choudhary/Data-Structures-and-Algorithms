class Solution {
public:
    // [1]. Recursion + Memo
    /*
    bool ispalindrome(int start,int end,string& s){
        while(start < end){
            if(s[start] != s[end]) return false;
            start++;
            end--;
        }
        return true;
    }
    int fn(int i,string& s,vector<int>& dp){
        if(i==s.size()) return -1;
        if(dp[i] != -1) return dp[i];
        int ans = INT_MAX;
        for(int j=i;j<s.size();j++){
            if(ispalindrome(i,j,s)){
                int cost = 1 + fn(j+1,s,dp);
                ans = min(ans,cost);
            }
        }
        return dp[i] = ans;
    }
    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n,-1);
        return fn(0,s,dp);
    }
    */

    // [2]. Bottom UP DP
    bool ispalindrome(int start,int end,string& s){
        while(start < end){
            if(s[start] != s[end]) return false;
            start++;
            end--;
        }
        return true;
    }
    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n+1,0);
        for(int i=n-1;i>=0;i--){
            int ans = INT_MAX;
            for(int j=i;j<n;j++){
                if(ispalindrome(i,j,s)){
                    int cost;
                    if(j+1 == n){
                        cost = 0;
                    }
                    else cost = 1+dp[j+1];
                    ans = min(ans,cost);
                }   
            }
            dp[i] = ans;
        }
        return dp[0];
    }
};