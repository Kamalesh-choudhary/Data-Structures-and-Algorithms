class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> vis(m,vector<bool>(n,false));

        stack<pair<int,int>> st;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1)st.push({i,j});
            }
        }

        int cnt = 0;
        while(!st.empty()){
            auto [x,y] = st.top();st.pop();
            for(int i=0;i<n;i++){
                if(i==y) continue;
                if(grid[x][i] == 1){
                    cnt += (vis[x][i] == false);
                    vis[x][i] = true;
                }
            }
            for(int i=0;i<m;i++){
                if(i==x) continue;
                if(grid[i][y] == 1){
                    cnt += (vis[i][y] == false);
                    vis[i][y] = true;
                }
            }
        }
        return cnt;
    }
};