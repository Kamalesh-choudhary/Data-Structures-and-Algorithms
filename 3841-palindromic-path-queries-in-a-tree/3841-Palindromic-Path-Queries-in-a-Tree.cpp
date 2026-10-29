
class Solution {
public:
    int n, LOG, timer;
    string s;
    vector<vector<int>> adj, up;
    vector<int> tin, tout, depth, bit;

    // XOR Fenwick Tree
    void add(int i, int val) {
        for (; i <= n; i += i & -i)
            bit[i] ^= val;
    }

    int sum(int i) {
        int res = 0;
        for (; i > 0; i -= i & -i)
            res ^= bit[i];
        return res;
    }

    // Range XOR update [l, r]
    void rangeUpdate(int l, int r, int val) {
        add(l, val);
        if (r < n)
            add(r + 1, val);
    }

    void dfs(int u, int p) {
        tin[u] = ++timer;
        up[0][u] = p;

        for (int k = 1; k < LOG; k++)
            up[k][u] = up[k - 1][up[k - 1][u]];

        for (int v : adj[u]) {
            if (v == p)
                continue;
            depth[v] = depth[u] + 1;
            dfs(v, u);
        }

        tout[u] = timer;
    }

    bool isAncestor(int u, int v) {
        return tin[u] <= tin[v] && tout[v] <= tout[u];
    }

    int lca(int u, int v) {
        if (isAncestor(u, v))
            return u;
        if (isAncestor(v, u))
            return v;

        for (int k = LOG - 1; k >= 0; k--) {
            if (!isAncestor(up[k][u], v))
                u = up[k][u];
        }

        return up[0][u];
    }

    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s,vector<string>& queries) {
        this->n = n;
        this->s = s;
        timer = 0;

        adj.assign(n, {});
        tin.assign(n, 0);
        tout.assign(n, 0);
        depth.assign(n, 0);

        LOG = 1;
        while ((1 << LOG) <= n)
            LOG++;

        up.assign(LOG, vector<int>(n, 0));
        bit.assign(n + 1, 0);

        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        dfs(0, 0);

        // Initialize prefix masks using subtree range updates
        for (int u = 0; u < n; u++) {
            int mask = 1 << (this->s[u] - 'a');
            rangeUpdate(tin[u], tout[u], mask);
        }

        vector<bool> ans;

        for (auto& line : queries) {
            istringstream iss(line);
            string op;
            int u;
            iss >> op >> u;

            if (op == "update") {
                char c;
                iss >> c;

                int oldMask = 1 << (this->s[u] - 'a');
                int newMask = 1 << (c - 'a');

                int delta = oldMask ^ newMask;

                if (delta) {
                    rangeUpdate(tin[u], tout[u], delta);
                    this->s[u] = c;
                }
            } else if (op == "query") {
                int v;
                iss >> v;

                int w = lca(u, v);

                int mask =
                    sum(tin[u]) ^ sum(tin[v]) ^ (1 << (this->s[w] - 'a'));

                ans.push_back((mask & (mask - 1)) == 0);
            }
        }

        return ans;
    }
};
