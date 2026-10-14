class DisjointSet{
    vector<int> parent,size;
public:
    DisjointSet(int n){
        size.resize(n+1,1);
        parent.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i] = i;
        }
    }
    int findParent(int node){
        if(node == parent[node]){
            return node;
        }
        return parent[node] = findParent(parent[node]);
    }
    void UnionBySize(int u,int v){
        int u_par = findParent(u);
        int v_par = findParent(v);
        if(u_par == v_par) return;
        if(size[u_par] < size[v_par]){
            parent[u_par] = v_par;
            size[v_par] += size[u_par];
        }
        else{
            parent[v_par] = u_par;
            size[u_par] += size[v_par];
        }
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int maxm = 0;
        int maxn = 0;
        for(auto &e:stones){
            maxm = max(maxm,e[0]);
            maxn = max(maxn,e[1]);
        }

        DisjointSet ds(maxm + maxn + 1);
        unordered_map<int,int> mpp;
        for(auto &e:stones){
            int i = e[0];
            int j = e[1] + maxm + 1;
            ds.UnionBySize(i,j);
            mpp[i] = 1;
            mpp[j] = 1;
        }

        int cnt = 0;
        for(auto &it : mpp){
            if(ds.findParent(it.first) == it.first){
                cnt++;
            }
        }

        return stones.size() - cnt;
    }
};