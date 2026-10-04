class Solution {
public:
    int minRotations(string s) {
        int prev = 0;
        int moves = 0;
        for(auto ch:s){
            int x = ch-'0';
            moves += min((prev-x+10)%10,(x-prev+10)%10);
            prev = x;
        }
        return moves;
    }
};