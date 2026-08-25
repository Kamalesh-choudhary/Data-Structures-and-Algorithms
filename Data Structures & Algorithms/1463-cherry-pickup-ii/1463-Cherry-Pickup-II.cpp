class Solution {
public:
    //1. Recursive + Memo
    /*
    int fn(int i,int j1,int j2,vector<vector<int>>& grid,vector<vector<vector<int>>>& dp){
        if(j1<0 || j1>=grid[0].size() || j2<0 || j2>=grid[0].size()){
            return -1e6;
        }
        if(i==grid.size()-1){
            if(j1 == j2){
                return grid[i][j1];
            }
            else{
                return grid[i][j1] + grid[i][j2];
            }
        }
        if(dp[i][j1][j2] != -1) return dp[i][j1][j2];
        int maxi = -1e8;
        vector<int> direction = {-1,0,1};
        for(int dj1=0;dj1<direction.size();dj1++){
            for(int dj2=0;dj2<direction.size();dj2++){
                if(j1 == j2) maxi = max(maxi,grid[i][j1] + fn(i+1,j1+direction[dj1],j2+direction[dj2],grid,dp));
                else maxi = max(maxi,grid[i][j1]+grid[i][j2] + fn(i+1,j1+direction[dj1],j2+direction[dj2],grid,dp));
            }
        }
        return dp[i][j1][j2] = maxi;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(n, -1)));
        return fn(0,0,n-1,grid,dp);
    }
    */

    //2. Bottom up DP
    /*int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(n, 0)));
        for(int j1 = 0;j1<n;j1++){
            for(int j2=0;j2<n;j2++){
                if(j1 == j2) dp[m-1][j1][j2] = grid[m-1][j2];
                else dp[m-1][j1][j2] = grid[m-1][j1] + grid[m-1][j2];
            }
        }
        for(int i=m-2;i>=0;i--){
            for(int j1=0;j1<n;j1++){
                for(int j2=0;j2<n;j2++){
                    int maxi = -1e8;
                    for(int dj1 = -1;dj1<=1;dj1++){
                        for(int dj2 = -1;dj2<=1;dj2++){
                            int value = 0;
                            if(j1 == j2) value = grid[i][j1];
                            else value = grid[i][j1] + grid[i][j2];
                            if(j1+dj1 >=0 && j1+dj1 < n && j2+dj2>=0 && j2+dj2<n)
                                value += dp[i+1][j1+dj1][j2+dj2];
                            else{
                                value += -1e8;
                            }
                            maxi = max(maxi,value);
                        }
                    }
                    dp[i][j1][j2] = maxi;
                }
            }
        }
        return dp[0][0][n-1];
    }
    */

    //3. Space Optimization
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> front(n,vector<int>(n,0));
        for(int j1 = 0;j1<n;j1++){
            for(int j2=0;j2<n;j2++){
                if(j1 == j2) front[j1][j2] = grid[m-1][j2];
                else front[j1][j2] = grid[m-1][j1] + grid[m-1][j2];
            }
        }
        for(int i=m-2;i>=0;i--){
            vector<vector<int>> temp(n,vector<int>(n,0));
            for(int j1=0;j1<n;j1++){
                for(int j2=0;j2<n;j2++){
                    int maxi = -1e8;
                    for(int dj1 = -1;dj1<=1;dj1++){
                        for(int dj2 = -1;dj2<=1;dj2++){
                            int value = 0;
                            if(j1 == j2) value = grid[i][j1];
                            else value = grid[i][j1] + grid[i][j2];
                            if(j1+dj1 >=0 && j1+dj1 < n && j2+dj2>=0 && j2+dj2<n)
                                value += front[j1+dj1][j2+dj2];
                            else{
                                value += -1e8;
                            }
                            maxi = max(maxi,value);
                        }
                    }
                    temp[j1][j2] = maxi;
                }
            }
            front = temp;
        }
        return front[0][n-1];
    }

};