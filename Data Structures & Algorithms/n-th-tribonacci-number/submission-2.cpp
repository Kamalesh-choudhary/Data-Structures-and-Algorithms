class Solution {
public:
    int dfs(int i,vector<int>& memo){
        if(i==0){
            return 0;
        }
        if(i==1 || i==2){
            return 1;
        }
        if(memo[i]!=-1){
            return memo[i];
        }
        return memo[i] = dfs(i-1,memo)+dfs(i-2,memo)+dfs(i-3,memo);
    }
    int tribonacci(int n) {
        vector<int> memo(n+1,-1);
        return dfs(n,memo);
    }
};