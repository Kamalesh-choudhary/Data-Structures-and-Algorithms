class Solution {
public:
    int longest_string;
    set<string> ans;

    void dfs(string& s,int idx,string& curr,int l_count,int r_count){
        if(idx == s.size()){
            if(l_count == r_count){
                if(curr.size() > longest_string){
                    longest_string = curr.size();
                    ans.clear();
                    ans.insert(curr);
                }
                else if(curr.size() == longest_string){
                    ans.insert(curr);
                }
            }
        }
        else{
            char cur_char = s[idx];
            if(cur_char == '('){
                curr.push_back(cur_char);
                dfs(s,idx+1,curr,l_count+1,r_count);
                curr.pop_back();
                
                dfs(s,idx+1,curr,l_count,r_count);
            }
            else if(cur_char == ')'){
                dfs(s,idx+1,curr,l_count,r_count);
                if(l_count > r_count){
                    curr.push_back(cur_char);
                    dfs(s,idx+1,curr,l_count,r_count+1);
                    curr.pop_back();
                }
            }
            else{
                curr.push_back(cur_char);
                dfs(s,idx+1,curr,l_count,r_count);
                curr.pop_back();
            }
        }
    }

    vector<string> removeInvalidParentheses(string s) {
        longest_string = 0;
        ans.clear();
        string curr;
        dfs(s,0,curr,0,0);
        vector<string> res;
        for(auto x:ans){
            res.push_back(x);
        }
        return res;
    }

};