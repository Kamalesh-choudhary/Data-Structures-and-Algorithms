class Solution {
public:
    static const int MOD = 1e9+7;
    vector<vector<pair<int,int>>> adj;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<long long> dist(n,LLONG_MAX), ways(n,0);
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> pq;
        adj.assign(n,{});
        for(auto &e:roads){
            adj[e[0]].push_back({e[1],e[2]});
            adj[e[1]].push_back({e[0],e[2]});
        }
        dist[0] = 0;
        ways[0] = 1;
        pq.push({0,0});
        while(!pq.empty()){
            auto [dis,node] = pq.top();pq.pop();
            if(dis > dist[node]) continue;
            for(auto &x:adj[node]){
                int adjNode = x.first;
                int edw = x.second;
                if(dis + edw < dist[adjNode]){
                    dist[adjNode] = dis + edw;
                    pq.push({dist[adjNode],adjNode});
                    ways[adjNode] = ways[node];
                }
                else if(dis + edw == dist[adjNode]){
                    ways[adjNode] = (ways[adjNode] + ways[node])%MOD;
                }
            }
        }
        return ways[n-1]%MOD;
    }
};