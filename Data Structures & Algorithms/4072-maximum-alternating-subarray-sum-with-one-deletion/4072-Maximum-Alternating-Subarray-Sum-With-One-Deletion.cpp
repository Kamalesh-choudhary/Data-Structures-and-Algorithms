class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        const long long NEG = -1e18;
        long long ans = NEG;
        long long p0 = NEG;
        long long m0 = NEG;
        long long p1 = NEG;
        long long m1 = NEG;
        for(long long x:nums){
            long long prev_p0 = p0;
            long long prev_p1 = p1;
            long long prev_m0 = m0;
            long long prev_m1 = m1;

            long long new_m0 = max(x,prev_p0 + x);
            long long new_p0 = prev_m0 - x;

            long long new_p1 = max(prev_p0,prev_m1-x);
            long long new_m1 = max(prev_m0,prev_p1+x);

            p0 = new_p0;
            m0 = new_m0;
            p1 = new_p1;
            m1 = new_m1;

            ans = max({ans,p0,m0,p1,m1});
        }
        return ans;
    }
};