class Solution {
public:
    //1. Recursive + Memo
    /*
    int fn(int i,int buy,int cap,vector<int>& prices,vector<vector<vector<int>>>& dp){
        if(cap == 0){
            return 0;
        }

        if(i==prices.size()){
            return 0;
        }
        if(dp[i][buy][cap] != -1) return dp[i][buy][cap];
        int profit = 0;
        if(buy){
            profit = max(-prices[i]+fn(i+1,0,cap,prices,dp),0+fn(i+1,1,cap,prices,dp));
        }
        else{
            profit = max(prices[i]+fn(i+1,1,cap-1,prices,dp),0+fn(i+1,0,cap,prices,dp));
        }
        return dp[i][buy][cap] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,-1)));
        return fn(0,1,2,prices,dp);

    }
    */

    //2. Bottom UP DP
    /*
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(
            n+1 , vector<vector<int>>(2, vector<int>(3, 0)));

        for(int i=n-1;i>=0;i--){
            for(int buy = 1;buy>=0;buy--){
                for(int cap = 1;cap<=2;cap++){
                    int profit = 0;
                    if(buy){
                        profit = max(-prices[i] + dp[i + 1][0][cap],
                         0 + dp[i + 1][1][cap]);
                    }
                    else{
                        profit = max(prices[i]+dp[i+1][1][cap-1],0+dp[i+1][0][cap]);
                    }
                    dp[i][buy][cap] = profit;
                }
            }
        }

        return dp[0][1][2];
    }
    */

    //3. Space Optimization
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> front(2,vector<int>(3,0)),curr(2,vector<int>(3,0));

        for (int i = n - 1; i >= 0; i--) {
            for (int buy = 1; buy >= 0; buy--) {
                for (int cap = 1; cap <= 2; cap++) {
                    int profit = 0;
                    if (buy) {
                        profit = max(-prices[i] + front[0][cap],
                                     0 + front[1][cap]);
                    } else {
                        profit = max(prices[i] + front[1][cap - 1],
                                     0 + front[0][cap]);
                    }
                    curr[buy][cap] = profit;
                }
            }
            front = curr;
        }

        return front[1][2];
    }
};