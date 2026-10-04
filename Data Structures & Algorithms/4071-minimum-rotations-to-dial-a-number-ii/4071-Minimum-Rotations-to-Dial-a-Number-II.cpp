class Solution {
public:
    int dist(int a,int b){
        int d = abs(a-b);
        return min(d,10-d);
    }
    int minRotations(int n, string s) {
        int ans = 0;
        int prev = 0;
        for(int i=0;i<n;i++){
            int x = s[i]-'0';
            ans += dist(prev,x);
            prev = x;
        }

        int total = ans;
        for(int i=0;i<n;i++){
            int x = s[i]-'0';
            int curr;
            if(i==0){
                curr = total - dist(0,s[0]-'0') + dist(0,s[n-1]-'0');
            }
            else{
                curr = total - dist(s[i-1]-'0',s[i]-'0') + dist(s[i-1]-'0',s[n-1]-'0');
            }
            ans = min(ans,curr);
        }
        return ans;
    }
};