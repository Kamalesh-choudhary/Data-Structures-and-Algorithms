class Solution {
public:
    // Using Recursion + Combinatorics
    typedef long long ll;
    const ll  MOD = 1e9+7;
    vector<vector<ll>> comb;
    int solve(vector<int>& nums){
        int n = nums.size();
        if(n<3) return 1;
        vector<int> left,right;
        int root = nums[0];
        for(int i=1;i<n;i++){
            if(nums[i] < root) left.push_back(nums[i]);
            else right.push_back(nums[i]);
        }
        ll x = solve(left)%MOD;
        ll y = solve(right)%MOD;
        ll z = comb[n-1][left.size()];
        return ((x * y) % MOD * z) % MOD;
    }

    int numOfWays(vector<int>& nums) {
        int n = nums.size();
        comb.resize(n+1);
        for(int i=0;i<=n;i++){
            comb[i] = vector<ll>(i+1,1);
            for(int j=1;j<i;j++){
                comb[i][j] = (comb[i-1][j-1] + comb[i-1][j]) % MOD;
            }
        }
        return (solve(nums)-1)%MOD;
    }
};