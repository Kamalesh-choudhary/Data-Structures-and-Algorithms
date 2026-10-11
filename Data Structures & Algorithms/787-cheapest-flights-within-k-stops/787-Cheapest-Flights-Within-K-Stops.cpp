class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,int k) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto& e : flights)
            adj[e[0]].push_back({e[1], e[2]});

        vector<int> dist(n, 1e9);
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,greater<>>pq;
        pq.push({0, src, 0});

        while (!pq.empty()) {
            auto [cost, node, stops] = pq.top();pq.pop();
            if (node == dst)
                return cost;
            if (stops > k || stops >= dist[node])
                continue;
            dist[node] = stops;
            for (auto& [nxt, wt] : adj[node])
                pq.push({cost + wt, nxt, stops + 1});
        }
        return -1;
    }
};