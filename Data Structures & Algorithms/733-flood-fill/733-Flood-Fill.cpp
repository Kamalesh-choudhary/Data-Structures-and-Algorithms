class Solution {
public:
//1. DFS Solution
/*
    void dfs(int i,int j,int color,vector<vector<int>>& grid){
        int start = grid[i][j];
        if(start == color) return;
        grid[i][j] = color;
        vector<pair<int,int>> dir = {
            {0,1},
            {1,0},
            {-1,0},
            {0,-1}
        };

        for(auto [x,y]:dir){
            int ni = i+x;
            int nj = j+y;
            if(ni>=0 && ni<grid.size() && nj>=0 && nj<grid[0].size() && grid[ni][nj] == start){
                dfs(ni,nj,color,grid);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        dfs(sr,sc,color,image);
        return image;
    }
*/

//2. BFS Solution
    void bfs(int i,int j,int color,vector<vector<int>>& grid){
        int start = grid[i][j];
        if(start == color) return;
        grid[i][j] = color;
        vector<pair<int,int>> dir = {
            {0,1},
            {1,0},
            {-1,0},
            {0,-1}
        };
        queue<pair<int,int>> q;
        q.push({i,j});
        while(!q.empty()){
            auto [x,y] = q.front();q.pop();
            for(auto [a,b]:dir){
                int ni = a+x;
                int nj = b+y;
                if(ni>=0 && ni<grid.size() && nj>=0 && nj<grid[0].size() && grid[ni][nj] == start){
                    grid[ni][nj] = color;
                    q.push({ni,nj});
                }
            }
        }

    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        bfs(sr,sc,color,image);
        return image;
    }
};