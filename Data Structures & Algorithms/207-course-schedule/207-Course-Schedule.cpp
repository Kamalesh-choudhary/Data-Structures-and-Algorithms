class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses,0);
        unordered_map<int,vector<int>> adj;
        for(auto &e:prerequisites){
            int u = e[0];
            int v = e[1];
            adj[v].push_back(u);
            indegree[u]++;
        } 
        int completed = 0;
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        while(!q.empty()){
            completed++;
            int ele = q.front();q.pop();
            for(auto x:adj[ele]){
                indegree[x]--;
                if(indegree[x] == 0){
                    q.push(x);
                }
            }
        }
        return completed == numCourses;
    }
};