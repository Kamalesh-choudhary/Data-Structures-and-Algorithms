class Solution {
public:
    //1. DFS Solution
    /*
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
    */

    // BFS Solution
    void bfs(int i,int j,vector<vector<char>>& grid,vector<vector<int>>& vis){
        grid[i][j] = '0';
        vector<pair<int,int>> dir = {
            {0,1},
            {1,0},
            {-1,0},
            {0,-1}
        };
        queue<pair<int,int>> q;
        q.push({i,j});
        vis[i][j] = 1;

        while(!q.empty()){
            auto [r,c] = q.front();
            q.pop();

            for(auto [x,y]:dir){
                int ni = r+x;
                int nj = c+y;
                if(ni>=0 && ni<grid.size() && nj>=0 && nj<grid[0].size() && grid[ni][nj] =='1' && !vis[ni][nj]){
                    vis[ni][nj] = 1;
                    grid[ni][nj] = '0';
                    q.push({ni,nj});
                }
            }        
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int cnt = 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == '1'){
                    cnt++;
                    bfs(i,j,grid,vis);
                }
            }
        }

        return cnt;
    }
};