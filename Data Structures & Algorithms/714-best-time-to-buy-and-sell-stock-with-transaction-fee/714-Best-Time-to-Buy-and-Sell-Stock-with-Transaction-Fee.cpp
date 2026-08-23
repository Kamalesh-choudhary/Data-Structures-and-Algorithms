class Solution {
public:
    //1. Recursion + memo
    /*
    int fn(int i,int buy,vector<int>& prices,int fee,vector<vector<int>>& dp){

        if(i==prices.size()){
            return 0;
        }
        if(dp[i][buy] != -1) return dp[i][buy];
        int profit = 0;
        if(buy){
            profit = max(-prices[i] + fn(i+1,0,prices,fee,dp),0+fn(i+1,1,prices,fee,dp));
        }
        else{
            profit = max(prices[i] - fee + fn(i+1,1,prices,fee,dp),0+fn(i+1,0,prices,fee,dp));
        }
        return dp[i][buy] = profit;
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2,-1));
        return fn(0,1,prices,fee,dp);
    }
    */

    //2. Bottom UP Dp
    /*
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2,0));
        for(int i=n-1;i>=0;i--){
            for(int buy = 0;buy<2;buy++){
                int profit = 0;
                if(buy){
                    profit = max(-prices[i] + dp[i+1][0],0+dp[i+1][1]);
                }
                else{
                    profit = max(prices[i] - fee + dp[i+1][1],0+dp[i+1][0]);
                }
                dp[i][buy] = profit;
            }
        }
        return dp[0][1];
    }
    */

    //3. Space Optimised
    
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<int> front(2,0),curr(2,0);
        for(int i=n-1;i>=0;i--){
            for(int buy = 0;buy<2;buy++){
                int profit = 0;
                if(buy){
                    profit = max(-prices[i] + front[0],0+front[1]);
                }
                else{
                    profit = max(prices[i] - fee + front[1],0+front[0]);
                }
                curr[buy] = profit;
            }
            front = curr;
        }
        return front[1];
    }
};