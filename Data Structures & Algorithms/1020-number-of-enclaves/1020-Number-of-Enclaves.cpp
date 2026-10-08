class Solution {
public:
    vector<vector<int>> not_land;
    int m,n;
    int dir[4][2] ={{0,1},{1,0},{-1,0},{0,-1}};

    void dfs(int i,int j,vector<vector<int>>& grid){
        not_land[i][j] = 1;
        for(auto &d:dir){
            int nr = i+d[0];
            int nc = j+d[1];
            if(nr>=0 && nr<m && nc>=0 && nc<n && !not_land[nr][nc] && grid[nr][nc] == 1){
                not_land[nr][nc] = true;
                dfs(nr,nc,grid);
            }
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        not_land.resize(m,vector<int>(n,0));
        for(int i=0;i<n;i++){
            if(grid[0][i] == 1){
                dfs(0,i,grid);
            }
            if(grid[m-1][i] == 1){
                dfs(m-1,i,grid);
            }
        }
        for(int i=0;i<m;i++){
            if(grid[i][0] == 1){
                dfs(i,0,grid);
            }
            if(grid[i][n-1] == 1){
                dfs(i,n-1,grid);
            }
        }
        int cnt = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1 && !not_land[i][j]){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};