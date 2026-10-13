// Solution using the Disjoint union set Data Structure.
class DisJointSet{
    vector<int> parent,size;
public:
    DisJointSet(int n){
        parent.resize(n+1);
        size.resize(n+1,1);
        for(int i=0;i<=n;i++){
            parent[i] = i;
        }
    }

    int findParent(int x){
        if (x == parent[x]) return x;
        return parent[x] = findParent(parent[x]);
    }

    void UnionBySize(int u,int v){
        int u_par = findParent(u);
        int v_par = findParent(v);
        if(u_par == v_par) return;
        if(u_par < v_par){
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

    int count_parent(){
        int cnt = 0;
        for(int i=0;i<parent.size();i++){
            if(parent[i] == i) cnt++;
        }
        return cnt;
    }
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        DisJointSet ds(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]) ds.UnionBySize(i,j);
            }
        }
        return ds.count_parent()-1;
    }
};