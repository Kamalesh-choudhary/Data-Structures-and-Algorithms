class Solution {
public:
    void dfs(int i,int j,vector<vector<int>>& grid){
        grid[i][j] = 1;
        int dir[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
        for(auto d:dir){
            int nr = i+d[0];
            int nc = j+d[1];
            if(nr>=0 && nr<grid.size() && nc>=0 && nc<grid[0].size() && grid[nr][nc] == 0){
                dfs(nr,nc,grid);
            }
        }
    }
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        for(int i=0;i<m;i++){
            if(grid[i][0] == 0) dfs(i,0,grid);
            if(grid[i][n-1] == 0) dfs(i,n-1,grid);
        }
        for(int j=0;j<n;j++){
            if(grid[0][j] == 0) dfs(0,j,grid);
            if(grid[m-1][j] == 0) dfs(m-1,j,grid);
        }

        int cnt = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 0){
                    cnt++;
                    dfs(i,j,grid);
                }
            }
        }
        return cnt;
    }
};