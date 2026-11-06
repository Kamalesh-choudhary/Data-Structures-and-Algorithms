class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        int n_logs = logs.size();
        int n_queries = queries.size();

        sort(logs.begin(),logs.end(),[](const auto a, const auto b){
            return a[1] < b[1];
        });

        vector<pair<int,int>> sorted_query;
        for(int i=0;i<n_queries;i++){
            sorted_query.push_back({queries[i],i});
        }
        sort(sorted_query.begin(),sorted_query.end());

        unordered_map<int,int> active_cnt;
        vector<int> ans(n_queries,0);
        int left = 0;
        int right = 0;

        for(const auto& [q_time,orig_idx]:sorted_query){
            int start = q_time - x;
            int end = q_time;
            
            while(right < n_logs && logs[right][1] <= end){
                int src_idx = logs[right][0];
                active_cnt[src_idx]++;
                right++;
            }
            while(left < n_logs && logs[left][1] < start){
                int src_idx = logs[left][0];
                active_cnt[src_idx]--;
                if(active_cnt[src_idx] == 0)active_cnt.erase(src_idx);
                left++;
            }
            ans[orig_idx] = n - active_cnt.size();
        }

        return ans;
    }
};