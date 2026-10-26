class Solution {
public:
    long long dfs(int i,int j, vector<vector<int>>& grid){
        long long ele = grid[i][j];
        grid[i][j] = 0;
        int dir[4][2] = {{1,0},{0,1},{0,-1},{-1,0}};
        for(auto d:dir){
            int nr = i+d[0];
            int nc = j+d[1];
            if(nr>=0 && nr<grid.size() && nc>=0 && nc<grid[0].size() && grid[nr][nc]!=0){
                ele+=dfs(nr,nc,grid);
            }
        }
        return ele;
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int total = 0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]!=0){
                    long long tmp=dfs(i,j,grid);
                    if(tmp%k==0)total++;
                }
            }
        }
        return total;
    }
};