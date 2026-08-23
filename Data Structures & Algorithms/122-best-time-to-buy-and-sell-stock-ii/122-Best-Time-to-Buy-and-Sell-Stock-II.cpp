class Solution {
public:
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
};