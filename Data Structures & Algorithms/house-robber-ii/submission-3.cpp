class Solution {
public:
    int helper(vector<int> nums){
        if(nums.size() == 1){
            return nums[0];
        }
        int prev2 = nums[0];
        int prev = max(nums[0],nums[1]);
        for(int i=2;i<nums.size();i++){
            int curr = max(prev,prev2+nums[i]);
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
    int rob(vector<int>& nums) {
        if(nums.size() == 1){
            return nums[0];
        }
        return max(helper(vector<int>(nums.begin()+1,nums.end())),helper(vector<int>(nums.begin(),nums.end()-1)));
    }
};
