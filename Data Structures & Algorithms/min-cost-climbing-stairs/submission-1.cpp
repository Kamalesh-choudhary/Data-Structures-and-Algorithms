class Solution {
public:
    int dfs(int i,vector<int>& cost,vector<int>& memo){
        if(i>=cost.size()){
            return 0;
        }
        if(memo[i] != -1){
            return memo[i];
        }
        return memo[i] = min(cost[i] + dfs(i+1,cost,memo),cost[i] + dfs(i+2,cost,memo));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> memo(cost.size(),-1);
        return min(dfs(0,cost,memo),dfs(1,cost,memo));
    }
};
