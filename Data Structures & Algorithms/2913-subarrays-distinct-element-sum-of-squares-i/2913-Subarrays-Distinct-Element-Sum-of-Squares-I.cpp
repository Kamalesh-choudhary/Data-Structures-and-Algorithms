class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int cnt = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            unordered_map<int,int> mpp;
            for(int j=i;j<n;j++){
                mpp[nums[j]]++;
                cnt += mpp.size() * mpp.size();
            }
        }
        return cnt;
    }
};