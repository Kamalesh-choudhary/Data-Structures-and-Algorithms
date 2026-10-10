class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>> q;
        q.push({beginWord,1});
        unordered_set<string> st(wordList.begin(),wordList.end());
        st.erase(beginWord);
        if(!st.count(endWord)) return 0;
        while(!q.empty()){
            auto [word,step] = q.front();q.pop();
            for(int i=0;i<word.size();i++){
                char original = word[i];
                for(char ch ='a';ch<='z';ch++){
                    word[i] = ch;
                    if(word == endWord) return step+1;
                    if(st.count(word)){
                        st.erase(word);
                        q.push({word,step+1});
                    }
                }
                word[i] = original;
            }
        }
        return 0;
    }
};