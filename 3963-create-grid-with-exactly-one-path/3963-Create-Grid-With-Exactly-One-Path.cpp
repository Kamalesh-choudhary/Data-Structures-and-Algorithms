class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> ans;
        for(int i=0;i<m;i++){
            string tmp = "";
            tmp += ".";
            if (i!= m-1){
                for(int j=1;j<n;j++){
                    tmp += '#';
                }
            }
            else{
                for(int j=1;j<n;j++){
                    tmp += '.';
                }
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};