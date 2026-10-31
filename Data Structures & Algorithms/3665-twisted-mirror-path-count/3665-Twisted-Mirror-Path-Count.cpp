class Solution {
public:
    vector<vector<int>> grid;
    int m, n;
    const int MOD = 1e9 + 7;
    vector<vector<array<int,2>>> dp;  // d: 0 = moving right, 1 = moving down

    int rec(int i, int j, int d) {
        if (i >= m || j >= n) return 0;
        if (i == m-1 && j == n-1) return grid[i][j] == 0;  // mirror at end deflects you out
        if (dp[i][j][d] != -1) return dp[i][j][d];

        int ans;
        if (grid[i][j] == 1) {
            // mirror: right -> down, down -> right
            ans = d == 0 ? rec(i+1, j, 1) : rec(i, j+1, 0);
        } else {
            ans = (rec(i, j+1, 0) + rec(i+1, j, 1)) % MOD;
        }
        return dp[i][j][d] = ans;
    }

    int uniquePaths(vector<vector<int>>& g) {
        grid = g;
        m = g.size(); n = g[0].size();
        dp.assign(m, vector<array<int,2>>(n, {-1, -1}));
        return rec(0, 0, 0);
    }
};
