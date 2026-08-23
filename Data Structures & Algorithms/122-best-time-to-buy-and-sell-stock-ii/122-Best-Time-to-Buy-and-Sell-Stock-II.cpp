class Solution {
public:
    //1. Recursion + Memo
    /*
    int fn(int i,int buy,vector<int>& prices,vector<vector<int>>& dp){
        if(i==prices.size()) return 0;
        if(dp[i][buy] != -1) return  dp[i][buy];
        int profit = 0;
        if(buy){
            profit = max(-prices[i] + fn(i+1,!buy,prices,dp),0+fn(i+1,buy,prices,dp));
        }
        else{
            profit = max(prices[i]+fn(i+1,!buy,prices,dp),0+fn(i+1,buy,prices,dp));
        }
        return dp[i][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(),vector<int>(2,-1));
        return fn(0,1,prices,dp);
    }
    */

    //2. Bottom Up

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2,0));

        for(int i=n-1;i>=0;i--){
            for(int buy=0;buy<2;buy++){
                long profit = 0;
                if(buy){
                    profit = max(-prices[i] + dp[i+1][0],0+dp[i+1][1]);
                }
                else{
                    profit = max(prices[i] + dp[i+1][1],0+dp[i+1][0]);
                }
                dp[i][buy] = profit;
            }
        }
        return dp[0][1];
    }
};