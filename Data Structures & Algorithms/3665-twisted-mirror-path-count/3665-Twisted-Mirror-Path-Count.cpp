class Solution {
public:
    /*
    1] Recursive + Memo Solution:- 
    
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

    2] Bottom UP DP:- 

    vector<vector<int>> grid;
    int m, n;
    const int MOD = 1e9 + 7;
    vector<vector<array<int,2>>> dp; 

    int uniquePaths(vector<vector<int>>& g) {
        grid = g;
        m = g.size();
        n = g[0].size();
        dp.assign(m+1, vector<array<int,2>>(n+1, {0, 0}));

        dp[m-1][n-1][0] = dp[m-1][n-1][1] = (grid[m-1][n-1] == 0);

        for(int i = m-1; i >= 0; i--) {
            for(int j = n-1; j >= 0; j--) {
                if(i == m-1 && j == n-1) continue;
                for(int d = 0; d < 2; d++) {
                    int ans;

                    if(grid[i][j] == 1) {
                        ans = (d == 0) ? dp[i+1][j][1] : dp[i][j+1][0];
                    }
                    else {
                        ans = (dp[i][j+1][0] + dp[i+1][j][1]) % MOD;
                    }
                    dp[i][j][d] = ans;
                }
            }
        }
        return dp[0][0][0];
    }

    3] Space Optimization because for every row we are depending on the front and curr row:- 

    vector<vector<int>> grid;
    int m, n;
    const int MOD = 1e9 + 7;
    vector<vector<array<int,2>>> dp; 

    int uniquePaths(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        vector<array<int, 2>> front(n+1, {0, 0});

        front[n-1] = {grid[m-1][n-1] == 0,grid[m-1][n-1] == 0};

        for(int i = m-1; i >= 0; i--) {
            vector<array<int, 2>> curr(n+1, {0, 0});

            for(int j = n-1; j >= 0; j--) {
                if(i == m-1 && j == n-1) {
                    curr[j] = front[j];
                    continue;
                }
                if(grid[i][j] == 1) {
                    curr[j][0] = front[j][1];
                    curr[j][1] = curr[j+1][0];
                }
                else {
                    int ans = (front[j][1] + curr[j+1][0]) % MOD;
                    curr[j][0] = ans;
                    curr[j][1] = ans;
                }
            }
            front = curr;
        }

        return front[0][0];
    }
    */

    //4] Even Further space optimization approach
    vector<vector<int>> grid;
    int m, n;
    const int MOD = 1e9 + 7;
    vector<vector<array<int,2>>> dp; 

    int uniquePaths(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<array<int, 2>> dp(n+1, {0, 0});

        dp[n-1] = {
            grid[m-1][n-1] == 0,
            grid[m-1][n-1] == 0
        };

        for(int i = m-1; i >= 0; i--) {
            for(int j = n-1; j >= 0; j--) {

                if(i == m-1 && j == n-1) continue;

                if(grid[i][j] == 1) {
                    dp[j][0] = dp[j][1];
                    dp[j][1] = dp[j+1][0];
                }
                else {
                    int ans = (dp[j+1][0] + dp[j][1]) % MOD;
                    dp[j][0] = ans;
                    dp[j][1] = ans;
                }
            }
        }

        return dp[0][0];
    }
};
