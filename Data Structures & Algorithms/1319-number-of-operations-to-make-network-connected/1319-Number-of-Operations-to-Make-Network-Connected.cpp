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
        return parent[x] = findParent(parent[x]);
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

    int countParent(){
        int cnt = 0;
        for(int i=0;i<parent.size()-1;i++){
            if(parent[i] == i) cnt++;
        }
        return cnt;
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisJointSet ds(n);
        int extra = 0;
        for(auto &e:connections){
            if(ds.areConnected(e[0],e[1])){
                extra++;
                continue;
            }
            ds.unionByMerge(e[0],e[1]);
        }
        int cc = ds.countParent();
        if(extra < cc-1) return -1;
        else return cc-1;
    }
};