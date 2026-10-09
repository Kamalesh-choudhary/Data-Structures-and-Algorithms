class Solution {
public:
    int sum_of_digits(int x){
        int total = 0;
        while(x){
            total += x%10;
            x /= 10;
        }
        return total;
    }
    int smallestIndex(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            if(sum_of_digits(nums[i]) == i) return i;
        }
        return -1;
    }
};