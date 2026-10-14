// Tarjan's Algorithm of Time in and low time
class Solution {
private:
    int timer = 1;
private:
    void dfs(int node,int parent){
        vis[node] = true;
        tin[node] = low[node] = timer;
        timer++;
        for(auto &x:adj[node]){
            if(x == parent) continue;
            if(!vis[x]){
                dfs(x,node);
                low[node] = min(low[node],low[x]);
                if(low[x] > tin[node]){
                    bridges.push_back({x,node});
                }
            }
            else{
                low[node] = min(low[node],tin[x]);
            }
        }
    }
public:
    vector<bool> vis;
    vector<int> tin;
    vector<int> low;
    vector<vector<int>> adj;
    vector<vector<int>> bridges;

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        adj.assign(n,{});
        for(auto &e:connections){
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vis.assign(n,false);
        tin.assign(n,0);
        low.assign(n,0);
        bridges.clear();
        dfs(0,-1);
        return bridges;
    }
};