class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        vector<int> frees(n,0);
        int cheapest = INT_MAX;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i!=j && items[j][0]%items[i][0]==0){
                    frees[i]++;
                }
            }
            cheapest = min(cheapest,items[i][1]);
        }

        vector<int> dp(budget+1,-1);
        dp[0] = 0;
        for(int j=0;j<n;j++){
            for(int b=budget;b>=items[j][1];b--){
                dp[b] = max(dp[b],dp[b-items[j][1]] + 1 + frees[j]);
            }
        }
        int ans = 0;
        for(int b=0;b<=budget;b++){
            if(dp[b] == -1) continue;
            int left = budget-b;
            int extra = left/cheapest;
            ans = max(ans,dp[b] + extra);
        }
        return ans;
    }
};