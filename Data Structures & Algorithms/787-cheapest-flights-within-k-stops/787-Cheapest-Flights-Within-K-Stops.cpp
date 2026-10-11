class Solution {
public:
    vector<vector<pair<int,int>>> adj;
    vector<int> dist;
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        adj.assign(n,{});
        for(auto &e:flights){
            adj[e[0]].push_back({e[1],e[2]});
        }
        dist.assign(n,1e9);
        queue<tuple<int,int,int>> q;  
        dist[src] = 0;
        q.push({0, src, 0});

        while (!q.empty()) {
            auto [stop, node, cost] = q.front();
            q.pop();

            if (stop > k) continue;
            for (auto &x : adj[node]) {
                int ele = x.first;
                int wt = x.second;
                if (cost + wt < dist[ele]) {
                    dist[ele] = cost + wt;
                    q.push({stop + 1, ele, dist[ele]});
                }
            }
        }
        return dist[dst] == 1e9 ? -1 : dist[dst];
    }
};