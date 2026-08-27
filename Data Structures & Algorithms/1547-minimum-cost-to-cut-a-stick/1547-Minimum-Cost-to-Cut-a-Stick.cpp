class Solution {
public:
/*
    //[1]. Recursion+ Memo =>

    int fn(int i,int j,vector<int>& ar,vector<vector<int>>& dp){
        if(i>j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int ans = 1e9;
        for(int c=i;c<=j;c++){
            int cost = (ar[j+1] - ar[i-1]) + fn(i,c-1,ar,dp) + fn(c+1,j,ar,dp);
            ans = min(ans,cost);
        }
        return dp[i][j] = ans;
    }
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        sort(cuts.begin(),cuts.end());
        vector<vector<int>> dp(cuts.size(),vector<int>(cuts.size(),-1));
        return fn(1,cuts.size()-2,cuts,dp);
    }
*/
    //[2]. Bottom UP Dynamic Programming =>

    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        sort(cuts.begin(),cuts.end());
        n = cuts.size();
        vector<vector<int>> dp(n,vector<int>(n,0));

        for(int i=n-1;i>=1;i--){
            for(int j=1;j<n-1;j++){
                if(i>j) continue;
                int ans = INT_MAX;
                for(int k=i;k<=j;k++){
                    int cost = cuts[j+1] - cuts[i-1] + dp[i][k-1] + dp[k+1][j];
                    ans = min(ans,cost);
                }
                dp[i][j] = ans;
            }
        }
        return dp[1][n-2];
    }
};