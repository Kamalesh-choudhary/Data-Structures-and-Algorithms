class Solution {
public:
//BFS Solution

    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int m = grid.size();
        int n = grid[0].size();
        if(m==1 && n==1){
            if(grid[0][0] == 1) return -1;
            else return 0;
        }
        int fresh = 0;
        int minutes = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 2){
                    q.push({i,j});
                }
                if(grid[i][j] == 1) fresh++;
            }
        }

        vector<pair<int,int>> dir = {
            {0,1},
            {1,0},
            {-1,0},
            {0,-1}
        };
        bool first = true;
        while(!q.empty()){
            if(!first)minutes++;
            if(first){
                first = false;
            }
            int sz = q.size();
            while(sz--){
                auto [i,j] = q.front();q.pop();
                for(auto [x,y]:dir){
                    int ni = i+x;
                    int nj = j+y;
                    if(ni>=0 && ni<m && nj>=0 && nj<n && grid[ni][nj] == 1){
                        grid[ni][nj] = 2;
                        fresh--;
                        q.push({ni,nj});
                    }
                }
            }
        }

        return fresh>0?-1:minutes;
    }
};