class Solution {
public:
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
};