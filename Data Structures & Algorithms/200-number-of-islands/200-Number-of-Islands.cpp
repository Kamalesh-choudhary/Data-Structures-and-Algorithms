class Solution {
public:
    void dfs(int i,int j,vector<vector<char>>& grid){
        grid[i][j] = '0';
        vector<pair<int,int>> dir = {
            {1,0},
            {0,1},
            {-1,0},
            {0,-1}
        };

        for(auto [x,y]:dir){
            int ni = i+x;
            int nj = j+y;
            if(ni<0 || ni>=grid.size() || nj<0 || nj>=grid[0].size() || grid[ni][nj] == '0'){
                continue;
            }
            else{
                dfs(ni,nj,grid);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int cnt = 0;
        int m = grid.size();
        int n = grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == '1'){
                    cnt++;
                    dfs(i,j,grid);
                }
            }
        }
        return cnt;
    }
};