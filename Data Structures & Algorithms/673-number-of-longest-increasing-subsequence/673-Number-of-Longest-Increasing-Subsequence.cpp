class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        int maxi = 0;
        vector<int> dp(n,1),cnt(n,1);
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[j] < nums[i] && dp[j]+1 > dp[i]){
                    dp[i] = 1+dp[j];
                    // Inherit the prev cnt since its increasing
                    cnt[i] = cnt[j];
                }
                else if(nums[j] < nums[i] && dp[j]+1 == dp[i]){
                    // Increment the cnt by prev cnt since this has been repeated
                    cnt[i] += cnt[j];
                }
            }
            maxi = max(maxi,dp[i]);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(dp[i] == maxi) ans += cnt[i];
        }
        return ans;
    }
};