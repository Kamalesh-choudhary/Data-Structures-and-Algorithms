class Solution {
  public:
    vector<vector<int>> adj;
    vector<int> inDegree;
    vector<int> ans;
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        adj.assign(numCourses,{});
        inDegree.assign(numCourses,0);
        ans.clear();
        for(auto &e:prerequisites){
            adj[e[1]].push_back(e[0]);
            inDegree[e[0]] += 1;
        }
        
        
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(inDegree[i] == 0){
                q.push(i);
            }
        }
        
        int cnt = 0;
        
        while(!q.empty()){
            int node = q.front(); q.pop();
            ans.push_back(node);
            cnt++;
            for(auto x:adj[node]){
                inDegree[x]--;
                if(inDegree[x] == 0){
                    q.push(x);
                }
            }
        }
        
        if(cnt == numCourses) return ans;
        else return {};
    }
};