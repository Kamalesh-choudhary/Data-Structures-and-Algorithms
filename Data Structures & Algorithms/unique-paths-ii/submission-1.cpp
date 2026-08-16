class Solution {
public:
    int fn(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& dp){
        if(i<0 || j<0 || grid[i][j] == 1){
            return 0;
        }
        if(i==0 && j==0){
            return 1;

        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        return dp[i][j] = fn(i-1,j,grid,dp) + fn(i,j-1,grid,dp);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return fn(m-1,n-1,obstacleGrid,dp);
    }
};