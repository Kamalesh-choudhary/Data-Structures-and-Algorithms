class Solution {
public:
    //1. Recursion + memo
    /*
    int fn(int i,int prev,vector<int>& nums,vector<vector<int>>& dp){
        if(i==nums.size()){
            return 0;
        }
        if(dp[i][prev+1] != -1) return dp[i][prev+1];
        int notpick = fn(i+1,prev,nums,dp);
        int pick = -1e5;
        if(prev == -1 || nums[prev] < nums[i]) pick = 1 + fn(i+1,i,nums,dp);
        return dp[i][prev+1] = max(pick,notpick);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return fn(0,-1,nums,dp);
    }
    */

    //2. Bottom Up DP
    /*
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        for(int i=n-1;i>=0;i--){
            for(int prev = n-1;prev >-2;prev--){
                int notpick = dp[i+1][prev+1];
                int pick = -1e5;
                if(prev == -1 || nums[prev] < nums[i]) pick = 1 + dp[i+1][i+1];
                dp[i][prev+1] = max(pick,notpick);
            }
        }
        return dp[0][0];
    }
    */

    //3. Space Optimization
    /*
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> front(n+1,0),curr(n+1,0);
        for(int i=n-1;i>=0;i--){
            for(int prev = n-1;prev >-2;prev--){
                int notpick = front[prev+1];
                int pick = -1e5;
                if(prev == -1 || nums[prev] < nums[i]) pick = 1 + front[i+1];
                curr[prev+1] = max(pick,notpick);
            }
            front = curr;
        }
        return front[0];
    }
    */

    //4. Binary Search Approach
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp;
        temp.push_back(nums.front());
        for(int i=1;i<n;i++){
            if(temp.back() < nums[i]){
                temp.push_back(nums[i]);
            }
            else{
                int idx = lower_bound(temp.begin(),temp.end(),nums[i]) - temp.begin();
                temp[idx] = nums[i];
            }
        }
        return temp.size();
    }

};