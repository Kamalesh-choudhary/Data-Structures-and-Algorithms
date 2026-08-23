class Solution {
public:
    //1. Recursion + Memo
    /*
    int fn(int i,int buy,int k,vector<int>& prices,vector<vector<vector<int>>>& dp){
        if(k==0){
            return 0;
        }
        if(i==prices.size()){
            return 0;
        }

        if(dp[i][buy][k] != -1) return dp[i][buy][k];
        int profit = 0;
        if(buy){
            profit = max(-prices[i] + fn(i+1,0,k,prices,dp),0+fn(i+1,1,k,prices,dp));
        }
        else{
            profit = max(prices[i] + fn(i+1,1,k-1,prices,dp),0+fn(i+1,0,k,prices,dp));
        }
        return dp[i][buy][k] = profit;
    }
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(k+1,-1)));
        return fn(0,1,k,prices,dp);
    }
    */

    //2. Bottom up DP
    /*
    int maxProfit(int kk, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(kk+1,0)));
        
        for(int i=n-1;i>=0;i--){
            for(int buy = 0;buy<2;buy++){
                for(int k=1;k<=kk;k++){
                    int profit = 0;
                    if(buy){
                        profit = max(-prices[i] + dp[i+1][0][k],0+dp[i+1][1][k]);
                    }
                    else{
                        profit = max(prices[i]+dp[i+1][1][k-1],0+dp[i+1][0][k]);
                    }
                    dp[i][buy][k] = profit;
                }
            }
        }
        return dp[0][1][kk];
    }
    */

    //3. Space Optimization
    int maxProfit(int kk, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> front(2,vector<int>(kk+1,0)),curr(2,vector<int>(kk+1,0));
        
        for(int i=n-1;i>=0;i--){
            for(int buy = 0;buy<2;buy++){
                for(int k=1;k<=kk;k++){
                    int profit = 0;
                    if(buy){
                        profit = max(-prices[i] + front[0][k],0+front[1][k]);
                    }
                    else{
                        profit = max(prices[i]+front[1][k-1],0+front[0][k]);
                    }
                    curr[buy][k] = profit;
                }
            }
            front = curr;
        }
        return front[1][kk];
    }
};