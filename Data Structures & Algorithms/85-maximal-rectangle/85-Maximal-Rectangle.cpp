using ll = long long;
class Solution {
public:
    int largestRectangleArea(vector<int>& ar) {
        int n = ar.size();

        stack<int> st;
        st.push(0);

        ll width = -1;
        ll max_ans = -1;

        ar.push_back(0);
        for(int i=0;i<=n;i++){
            while(!st.empty() && ar[i] < ar[st.top()]){
                int ele = st.top(); st.pop();
                if(!st.empty()){
                    width = i-st.top()-1;
                }
                else{
                    width = i;
                }

                ll area = (long long)ar[ele] * width;
                max_ans = max(max_ans,area);
            }
            st.push(i);
        }
        return (max_ans == -1? 0 : max_ans);
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int ans = 0;
        int n = matrix[0].size();
        vector<int> temp(n,0);
        for(int i=0;i<matrix.size();i++){
            int t = 0;
            for(auto x:matrix[i]){
                if(x=='1'){
                    temp[t] += 1;
                }
                else{
                    temp[t] = 0;
                }
                t++;
            }
            int curr = largestRectangleArea(temp);
            ans = max(ans,curr);
        }
        return ans;
    }
};