class Solution {
public:
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
};