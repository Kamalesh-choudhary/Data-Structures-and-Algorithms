class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int minim = prices[0];
        int profit = 0;
        for(int i=1;i<n;i++){
            int cost = prices[i] - minim;
            profit = max(profit,cost);
            minim = min(minim,prices[i]);
        }
        return profit;
    }
};