class Solution {
public:
    // [1]. Recursive + Memo
    /*
    int fn(int i,vector<int>& ar,int k,vector<int>& dp){
        if(i==ar.size()) return 0;
        if(dp[i] != -1) return dp[i];
        int ans = INT_MIN;
        int maxi = INT_MIN;
        for(int j=i;j<ar.size() && j<i+k;j++){
            maxi = max(maxi,ar[j]);
            int curr = maxi*(j-i+1) + fn(j+1,ar,k,dp);
            ans = max(ans,curr);
        }
        return dp[i] = ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n,-1);
        return fn(0,arr,k,dp);
    }
    */

    // [2]. Bottom UP Dynamic Programming
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n+1,0);
        for(int i=n-1;i>=0;i--){
            int ans = INT_MIN;
            int maxi = INT_MIN;
            for(int j=i;j<arr.size() && j<i+k;j++){
                maxi = max(maxi,arr[j]);
                int curr = maxi*(j-i+1) + dp[j+1];
                ans = max(ans,curr);
            }
            dp[i] = ans;
        }
        return dp[0];
    }
};