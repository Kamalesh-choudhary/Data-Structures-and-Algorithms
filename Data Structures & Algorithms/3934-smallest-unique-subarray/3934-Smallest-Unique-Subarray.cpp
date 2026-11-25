using ll = long long;
class Solution {
public:
    bool unique_len(vector<int>& nums,int l){
        int n = nums.size();
        int prime = 131;
        int mod = 1e9+7;
        vector<ll> power(l+1);
        power[0] = 1;
        for(int i=1;i<=l;i++){
            power[i] = (power[i-1]*prime)%mod;
        }
        ll hash = 0;
        for(int i=0;i<l;i++){
            hash = (hash+(ll)nums[i]*power[l-1-i])%mod;
        }
        unordered_map<ll,int> cnts;
        cnts[hash]++;
        ll new_hash = 0;
        for(int i=1;i<=n-l;i++){
            new_hash = (((hash-(ll)nums[i-1]*power[l-1])%mod+mod)*prime + nums[i+l-1])%mod;
            cnts[new_hash]++;
            hash = new_hash;
        }
        for(auto &p:cnts){
            if(p.second == 1){
                return true;
            }
        }
        return false;
    }
    
    int smallestUniqueSubarray(vector<int>& nums) {
        int low = 1;
        int high = nums.size();
        while(low < high){
            int mid = (low+high)/2;
            if (unique_len(nums,mid)){
                high = mid;
            }
            else{
                low = mid+1;
            }
        }
        return low;
    }
};