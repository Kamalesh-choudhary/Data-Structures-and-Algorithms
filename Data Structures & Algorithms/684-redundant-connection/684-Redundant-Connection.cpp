class DisJointSet{
    vector<int> parent,size;
public: 
    DisJointSet(int n){
        parent.assign(n+1,0);
        size.assign(n+1,1);
        for(int i=0;i<=n;i++) parent[i] = i;
    }

    int findParent(int x){
        if(x == parent[x]) return x;
        return findParent(parent[x]);
    }

    void unionByMerge(int u,int v){
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

    bool areConnected(int u,int v){
        return findParent(u) == findParent(v);
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int maxn = 0;
        for(auto &e:edges){
            maxn = max({e[0],e[1],maxn});
        }
        DisJointSet ds(maxn);
        vector<vector<int>> ans;
        for(auto &e:edges){
            int u = e[0];
            int v = e[1];
            if(!ds.areConnected(u,v)){
                ds.unionByMerge(u,v);
            }
            else{
                ans.push_back({u,v});
            }
        }
        return ans.back();
    }
};