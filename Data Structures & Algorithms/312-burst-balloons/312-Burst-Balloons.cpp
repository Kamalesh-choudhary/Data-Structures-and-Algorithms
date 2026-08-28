class Solution {
public:
    //1. Recursive + memo
    /*
    int fn(int i,int j,vector<int>& ar,vector<vector<int>>& dp){
        if(i>j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int ans = -1e8;
        for(int c=i;c<=j;c++){
            int cost = (ar[j+1] *ar[c] * ar[i-1]) + fn(i,c-1,ar,dp) + fn(c+1,j,ar,dp);
            ans = max(ans,cost);
        }
        return dp[i][j] = ans;
    }
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        vector<vector<int>> dp(nums.size(),vector<int>(nums.size(),-1));
        return fn(1,nums.size()-2,nums,dp);
    }
    */

    //2. Bottom UP Dynamic programming
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int i=n-1;i>0;i--){
            for(int j=1;j<n-1;j++){
                if(i>j) continue;
                int ans = -1e8;
                for(int c=i;c<=j;c++){
                    int cost = nums[i-1]*nums[c]*nums[j+1] + dp[i][c-1] + dp[c+1][j];
                    ans = max(ans,cost);
                }
                dp[i][j] = ans;
            }
        }
        return dp[1][n-2];
    }
};