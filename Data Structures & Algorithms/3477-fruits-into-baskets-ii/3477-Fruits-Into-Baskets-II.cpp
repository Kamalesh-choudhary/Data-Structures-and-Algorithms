class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int cnt = 0;
        int n = fruits.size();
        for(auto f:fruits){
            bool found = false;
            for(int i=0;i<n;i++){
                if(baskets[i] >= f){
                    found = true;
                    baskets[i] = 0;
                    break;
                }
            }
            if(!found) cnt++;
        }
        return cnt;
    }
};