class Solution {
public:
/*  1. Brute force Solution
    int lastStoneWeight(vector<int>& stones) {
        while(stones.size()>1){
            sort(stones.begin(),stones.end());
            int y = stones.back();stones.pop_back();
            int x = stones.back();stones.pop_back();
            stones.push_back(y-x);
        }
        return stones[0];
    }
    */
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(auto x:stones){
            pq.push(x);
        }
        while(pq.size() > 1){
            int y = pq.top();pq.pop();
            int x = pq.top();pq.pop();
            pq.push(y-x);
        }
        return pq.top();
    }
};