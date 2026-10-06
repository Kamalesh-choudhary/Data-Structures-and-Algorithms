class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int n = tickets.size();
        queue<pair<int,bool>> q;
        for(int i=0;i<n;i++){
            q.push({tickets[i],(i==k)});
        }
        int seconds = 0;
        while(true){
            auto [ele,isTarget] = q.front();
            seconds++;
            q.pop();
            ele--;
            if(ele == 0){
                if(isTarget){
                    return seconds;
                }
            }
            else{
                q.push({ele,isTarget});
            }
        }
        return 0;
    }
};