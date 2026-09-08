class Solution {
public:
    // BFS Solution
    /*
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> vis(n+1,false);
        
        int count = 0;
        for(int i=1;i<=n;i++){
            if(!vis[i]){
                count++;
                queue<int> q;
                q.push(i);
                vis[i] = true;
                while(!q.empty()){
                    int e = q.front();q.pop();
                    for(int i=0;i<isConnected[e-1].size();i++){
                        if(isConnected[e-1][i] == 1 && !vis[i+1]){
                            vis[i+1] = true;
                            q.push(i+1);
                        }
                    }
                }
            }
        }

        return count;
    }
    */

    // DFS Solution
    void dfs(int node,vector<vector<int>>& matrix,vector<bool>& vis){
        vis[node] = true;
        for(int i=0;i<matrix[node-1].size();i++){
            if(matrix[node-1][i] == 1 && !vis[i+1]){
                dfs(i+1,matrix,vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> vis(n+1,false);
        int count = 0;
        for(int i=1;i<=n;i++){
            if(!vis[i]){
                count++;
                dfs(i,isConnected,vis);
            }
        }
        return count;
    }
};