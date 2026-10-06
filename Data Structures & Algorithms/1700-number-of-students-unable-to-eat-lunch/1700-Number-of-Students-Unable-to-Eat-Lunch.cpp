class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> q;
        int zero = 0,one = 0;
        for(auto x:students){
            q.push(x);
            if(x==0)zero++;
            else one++;
        }
        int i = 0;
        while(!q.empty()){
            if(q.front() == sandwiches[i]){
                i++;
                if(q.front() == 0)zero--;
                else one--;
                q.pop();
            }
            else{
                if(zero == 0 || one == 0){
                    return q.size();
                }
                int t = q.front();
                q.pop();
                q.push(t);
            }
        }
        return 0;
    }
};