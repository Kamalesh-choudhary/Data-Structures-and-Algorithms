class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int n = nums.size();
        bool sorted = true;
        for(int i=0;i<n;i++){
            if(nums[i] != i) sorted = false;
        }
        if(sorted) return 0;

        int ans = 0;
        for(int i=0;i<32;i++){
            bool exist = true;
            for(int j=0;j<n;j++){
                if(nums[j] != j && !(nums[j]&(1<<i))) exist = false;
            }
            if(exist) ans |= (1<<i);
        }
        return ans;
    }
};