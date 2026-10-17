class Solution {
public:
    int findDigitSum(int n){
        int total = 0;
        while(n){
            total += n%10;
            n /= 10;
        }
        return total;
    }

    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++){
            int x = nums[i];
            v.push_back({x,i});
        }
        vector<bool> vis(n,false);
        sort(v.begin(),v.end(),[&](auto& a,auto& b){
            int a_sum = findDigitSum(a.first);
            int b_sum = findDigitSum(b.first);
            if(a_sum == b_sum) return a.first<b.first;
            else return a_sum < b_sum;
        });
        int swaps = 0;
        for(int i=0;i<n;i++){
            if(vis[i] || v[i].second == i) continue;
            int j = i;
            int cycle = 0;
            while(!vis[j]){
                vis[j] = true;
                j = v[j].second;
                cycle++;
            }
            swaps += cycle-1;
        }
        return swaps;
    }
};