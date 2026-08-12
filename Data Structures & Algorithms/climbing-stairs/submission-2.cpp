class Solution {
public:
    int dfs(int i,int n,vector<int>& memo){
        if(i>=n){
            return i==n;
        }
        if(memo[i] != -1){
            return memo[i];
        }
        return memo[i] = dfs(i+1,n,memo)+dfs(i+2,n,memo);
    }
    int climbStairs(int n) {
        vector<int> memo(n+1,-1);
        return dfs(0,n,memo);
    }
};
