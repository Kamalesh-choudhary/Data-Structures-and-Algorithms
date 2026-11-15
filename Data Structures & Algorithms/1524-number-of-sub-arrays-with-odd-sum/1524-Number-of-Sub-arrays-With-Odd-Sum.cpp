class Solution {
public:
    static const int MOD = 1e9 + 7;
    vector<vector<vector<int>>> dp;

    int solve(int i, vector<int>& nums, int active, int parity) {
        if (i == nums.size()) return 0;

        int &res = dp[i][active][parity];
        if (res != -1) return res;

        res = 0;

        if (!active) {
            res = (res + solve(i + 1, nums, 0, 0)) % MOD;

            int p = nums[i] % 2;

            res = (res + (p == 1)) % MOD;
            res = (res + solve(i + 1, nums, 1, p)) % MOD;
        }
        else {
            int p = parity ^ (nums[i] % 2);

            res = (res + (p == 1)) % MOD;
            res = (res + solve(i + 1, nums, 1, p)) % MOD;
        }

        return res;
    }

    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();

        dp.assign(n, vector<vector<int>>(2, vector<int>(2, -1)));

        return solve(0, arr, 0, 0);
    }
};