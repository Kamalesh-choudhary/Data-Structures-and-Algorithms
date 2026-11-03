class Solution {
public:
    int minMoves(vector<int>& nums) {
        int mx= *max_element(nums.begin(),nums.end());
        int total=accumulate(nums.begin(),nums.end(),0);
        return (mx*nums.size())-total;
    }
};