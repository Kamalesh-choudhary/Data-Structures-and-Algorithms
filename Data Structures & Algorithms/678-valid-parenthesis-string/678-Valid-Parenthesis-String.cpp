class Solution {
public:
    string s;
    int n;
    vector<vector<int>> dp;
    auto solve(int i,int curr) -> bool{
        if(curr < 0) return false;
        if(i==n) return curr == 0;
        if(dp[i][curr] != -1) return dp[i][curr];
        if(s[i] == '('){
            return dp[i][curr] = solve(i+1,curr+1);
        }
        if(s[i] == ')'){
            return dp[i][curr] = solve(i+1,curr-1);
        }
        return dp[i][curr] = solve(i+1,curr+1) || solve(i+1,curr-1) || solve(i+1,curr);
    }
    bool checkValidString(string st) {
        s = st;
        n = st.size();
        dp.assign(n,vector<int>(n+1,-1));
        return solve(0,0);
    }
};