class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        if(n==1){
            return {0};
        }
        vector<int> ans;
        vector<int> pref(n,0),suff(n,0);
        pref[1] = nums[0];
        for(int i=2;i<n;i++){
            pref[i] = nums[i-1] + pref[i-1];
        }
        suff[n-2] = nums[n-1];
        for(int i=n-3;i>=0;i--){
            suff[i] = nums[i+1] + suff[i+1];
        }
        for(int i=0;i<n;i++){
            ans.push_back(abs(pref[i] - suff[i]));
        }
        return ans;
    }
};