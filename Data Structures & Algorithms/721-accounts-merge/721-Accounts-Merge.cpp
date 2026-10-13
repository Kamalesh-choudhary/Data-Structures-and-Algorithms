// Disjoint Union Set Approach
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

    int count_parents(){
        int cnt = -1;
        for(int i=0;i<parent.size();i++){
            if(parent[i] == i) cnt++;
        }
        return cnt;
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        unordered_map<string,int> mpp;
        DisjointSet ds(n);

        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                const string &email = accounts[i][j];
                if(mpp.count(email)) ds.UnionBySize(i,mpp[email]);
                else mpp[email]=i;
            }
        }

        vector<vector<string>> email(n);
        for(int i=0;i<n;i++){
            int root = ds.findParent(i);
            for(int j=1;j<accounts[i].size();j++){
                email[root].push_back(accounts[i][j]);
            }
        }

        vector<vector<string>> ans;
        for(int i=0;i<n;i++){
            if(email[i].empty()) continue;
            sort(email[i].begin(),email[i].end());
            email[i].erase(unique(email[i].begin(),email[i].end()),email[i].end());
            vector<string> curr;
            curr.push_back(accounts[i][0]);
            curr.insert(curr.end(),email[i].begin(),email[i].end());
            ans.push_back(curr);
        }
        return ans;
    }
};