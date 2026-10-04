class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for(int k=0;k<=31;k++){
            int zcnt = 0,ocnt=0;
            for(auto x:nums){
                if(x&(1<<k)) ocnt++;
                else zcnt++;
            }
            if(ocnt%3 == 1) ans |= (1<<k);
        }
        return ans;
    }
};