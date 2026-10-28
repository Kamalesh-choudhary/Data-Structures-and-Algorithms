class Solution {
public:
    int m,n;
    vector<vector<vector<int>>> dp;
    int solve(int i,int j,vector<vector<int>>& grid,int xor_val){
        xor_val ^= grid[i][j];
        if(dp[i][j][xor_val] != -1) return dp[i][j][xor_val];
        if(i==m-1 && j==n-1) return xor_val;
        int down = INT_MAX,right = INT_MAX;
        if(i+1<m){
            down = solve(i+1,j,grid,xor_val);
        }
        if(j+1<n){
            right = solve(i,j+1,grid,xor_val);
        }
        return dp[i][j][xor_val] = min(down,right);
    }
    int minCost(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        dp.assign(m,vector<vector<int>>(n,vector<int>(1024,-1)));
        return solve(0,0,grid,0);
    }
};