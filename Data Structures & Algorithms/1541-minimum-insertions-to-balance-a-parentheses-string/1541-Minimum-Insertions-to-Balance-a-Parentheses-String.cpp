class Solution {
public:
    //Brute force Greedy + Stack Solution
    /*
    int minInsertions(string s) {
        int n = s.size();
        stack<char> st;
        int ans = 0;
        int i=0;
        while(i<n){
            auto c = s[i];
            if(c == '('){
                st.push(c);
                i++;
            }
            else{
                if(!st.empty() && st.top() == '('){
                    if(i+1<n && s[i+1] == c){
                        st.pop();
                        i+=2;
                    }
                    else{
                        ans++;
                        st.pop();
                        i+=1;
                    }
                }
                else{
                    ans++;
                    if(i+1 <n && s[i+1] == c){
                        i+=2;
                    }
                    else{
                        ans++;
                        i+=1;
                    }
                }
            }
        }
        //This is because if a test case contains only '((((((((' Then we need 2*st.size() amount of insertions 
        // Hence we consider doing a ans+2*st.size();
        return ans+2*st.size();
    }
    */
    // Removed that Stack and replaced it with a variable need
    
    int minInsertions(string s) {
        int ans = 0;
        int need = 0;

        for (char c : s) {
            if (c == '(') {
                if (need % 2 == 1) {
                    ans++;
                    need--;
                }
                need += 2;
            }
            else {
                need--;

                if (need < 0) {
                    ans++;
                    need = 1;
                }
            }
        }

        return ans + need;
    }
};