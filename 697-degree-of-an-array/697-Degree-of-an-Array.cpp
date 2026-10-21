class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        for(int i = 0; i<n; i++){
            mp[nums[i]]++;
        }
        int maxCount = 0;
        for(auto it : mp){
            maxCount = max(it.second, maxCount);
        }
        int ans = nums.size();
        for(auto it : mp){
            if(it.second == maxCount){
                int l = 0, r = n-1;
                while(nums[l] != it.first){
                    l++;
                }
                while(nums[r] != it.first){
                    r--;
                }
                ans = min(ans, r-l+1);
            }
        }
        return ans;
    }
};