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
};