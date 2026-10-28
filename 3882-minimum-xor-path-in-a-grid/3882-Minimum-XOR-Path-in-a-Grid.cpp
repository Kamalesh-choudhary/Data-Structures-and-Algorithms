class Solution {
public:
    int m, n;
    vector<vector<vector<int>>> dp;

    int minCost(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        dp.assign(m, vector<vector<int>>(n, vector<int>(1024, -1)));

        // Base case: destination cell
        for (int xor_val = 0; xor_val < 1024; xor_val++) {
            dp[m - 1][n - 1][xor_val] = xor_val ^ grid[m - 1][n - 1];
        }

        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (i == m - 1 && j == n - 1) continue;

                for (int xor_val = 0; xor_val < 1024; xor_val++) {
                    int new_xor = xor_val ^ grid[i][j];

                    int down = INT_MAX;
                    int right = INT_MAX;

                    if (i + 1 < m) {
                        down = dp[i + 1][j][new_xor];
                    }

                    if (j + 1 < n) {
                        right = dp[i][j + 1][new_xor];
                    }

                    dp[i][j][xor_val] = min(down, right);
                }
            }
        }

        return dp[0][0][0];
    }
};