class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto &e:edges){
            int u = e[0];
            int v = e[1];
            int w = e[2];
            adj[u].push_back({v,w});
        }
        vector<vector<long long>>dist(n,vector<long long>(k+1,LLONG_MAX));
        dist[0][1] = 0;

        priority_queue<tuple<long long,int,int>,vector<tuple<long long,int,int>>,greater<>> pq;
        pq.push({0,0,1});

        while(!pq.empty()){
            auto [cost,node,count] = pq.top();pq.pop();

            if (node == n-1)return cost;
            if (cost > dist[node][count])continue;

            for(auto [next,w]: adj[node]){
                int new_count;
                if (labels[next] == labels[node]){
                    new_count = count+1;
                }
                else{
                    new_count = 1;
                }

                if (new_count > k)continue;
                long long new_cost = cost+w;
                if (new_cost < dist[next][new_count]){
                    dist[next][new_count ] = new_cost;
                    pq.push({new_cost,next,new_count});
                }
            }
        }
        return -1;
    }
};