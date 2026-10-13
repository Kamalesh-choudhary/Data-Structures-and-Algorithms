class Solution {
public:
    // Using the floyd-Warshall Algorithm (for finding the distance from every node to the other node)
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> grid(n,vector<int>(n,1e8));
        for(auto &e:edges){
            grid[e[0]][e[1]] = e[2];
            grid[e[1]][e[0]] = e[2];
        }
        for(int i=0;i<n;i++) grid[i][i] = 0;

        for(int via = 0;via<n;via++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(grid[i][via] == 1e8 || grid[via][j] == 1e8) continue;
                    grid[i][j] = min(grid[i][j],grid[i][via] + grid[via][j]);
                }
            }
        }

        int ans = 1e8;
        int min_count = 1e8;
        for(int i=0;i<n;i++){
            int cnt = 0;
            for(int j=0;j<n;j++){
                if(grid[i][j] <= distanceThreshold) cnt++;
            }
            if(cnt <= min_count){
                min_count = cnt;
                ans = i;
            }
        }
        return ans;
    }
};