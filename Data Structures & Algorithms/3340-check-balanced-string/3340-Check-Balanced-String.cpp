class Solution {
public:
    bool isBalanced(string num) {
        int e = 0;
        int o = 0;
        for(int i=0;i<num.size();i++){
            if(i&1) o+= (num[i]-'0');
            else e+= (num[i]-'0');
        }
        return e == o;
    }
};