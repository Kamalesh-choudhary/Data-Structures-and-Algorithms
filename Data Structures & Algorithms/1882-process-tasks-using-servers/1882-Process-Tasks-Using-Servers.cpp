class Solution {
public:
    using tp = tuple<long long,int,int>;
    using pp = pair<int,int>;
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int m = tasks.size();
        int n = servers.size();
        vector<int> ans(m,0);
        //Busy: {end_time,server_wg,index}
        priority_queue<tp,vector<tp>,greater<tp>> pq;
        //free: {server_wg,index}
        priority_queue<pp,vector<pp>,greater<pp>> fr;
        for(int i=0;i<n;i++){
            fr.push({servers[i],i});
        }
        long long t = 0;
        for(int i=0;i<m;i++){
            t = max(t,(long long) i);
            if(fr.empty()) t = max(t,get<0>(pq.top()));
            while(!pq.empty() && get<0>(pq.top()) <= t){
                auto [end_time,wg,idx] = pq.top();pq.pop();
                fr.push({wg,idx});
            }
            auto [wg,idx] = fr.top();fr.pop();
            ans[i] = idx;
            pq.push({t+tasks[i],wg,idx});
        }
        return ans;
    }
};