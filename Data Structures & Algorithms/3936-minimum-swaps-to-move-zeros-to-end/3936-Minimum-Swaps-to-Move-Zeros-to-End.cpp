class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        int n = nums.size();
        int zeroes = count(nums.begin(),nums.end(),0);
        int cnt = 0;
        int r = n-1;
        while(zeroes--){
            if(nums[r] != 0) cnt++;
            r--;
        }
        return cnt;
    }
};