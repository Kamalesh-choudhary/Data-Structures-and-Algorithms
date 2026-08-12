class Solution {
public:
    int dfs(int i,int flag,vector<int>& nums,vector<vector<int>>& memo){
        if(i>=nums.size()){
            return 0;
        }
        if(flag && i == nums.size()-1){
            return 0;
        }
        if(memo[i][flag] != -1){
            return memo[i][flag];
        }
        return memo[i][flag] = max(dfs(i+1,flag,nums,memo),nums[i]+dfs(i+2,flag?true:false,nums,memo));
    }
    int rob(vector<int>& nums) {
        if(nums.size() == 1){
            return nums[0];
        }
        vector<vector<int>> memo(nums.size(),vector<int>(2,-1));
        return max(dfs(0,true,nums,memo),dfs(1,false,nums,memo));
    }
};
