class DSU {
public:
    vector<int> size;
    vector<int> parent;
    DSU(){
        size.assign(1e7,1);
        parent.assign(1e7,0);
        for(int i=0;i<parent.size();i++) parent[i] = i;
    }

    int findparent(int x){
        if(parent[x] == x){
            return x;
        }
        return findparent(parent[x]);
    }

    void merge(int u,int v){
        int u_p = findparent(u);
        int v_p = findparent(v);
        if(u_p == v_p) return;
        if(size[u_p] > size[v_p]){
            parent[v_p] = u_p;
            size[u_p] += size[v_p];
        }
        else{
            parent[u_p] = v_p;
            size[v_p] += size[u_p];
        }
    }
};

class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        DSU ds;

        // Row Wise merging
        for(int i=0;i<m;i++){
            int first = -1;
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1){
                    if(first == -1) first = i * n + j;
                    else ds.merge(first,i*n+j);
                }
            }
        }

        // Col Wise merging
        for(int j=0;j<n;j++){
            int first = -1;
            for(int i=0;i<m;i++){
                if(grid[i][j] == 1){
                    if(first == -1) first = i * n + j;
                    else ds.merge(first,i*n+j);
                }
            }
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1 && ds.size[ds.findparent(i*n+j)] > 1) ans++;
            }
        }
        return ans;
    }
};