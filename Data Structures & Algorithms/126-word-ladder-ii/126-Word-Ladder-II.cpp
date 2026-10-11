class Solution {
public:
    unordered_map<string,int> mpp;
    vector<vector<string>> ans;
    string beginWord;
    void dfs(string word,vector<string>& seq){
        if(word == beginWord){
            reverse(seq.begin(),seq.end());
            ans.push_back(seq);
            reverse(seq.begin(),seq.end());
            return;
        }
        int step = mpp[word];
        for(int i=0;i<word.size();i++){
            char original = word[i];
            for(char c='a';c<='z';c++){
                word[i] = c;
                if(mpp.count(word) && mpp[word]+1 == step){
                    seq.push_back(word);
                    dfs(word,seq);
                    seq.pop_back();
                }
            }
            word[i] = original;
        }
    }
    
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        this->beginWord = beginWord;
        queue<string> q;
        unordered_set<string> st(wordList.begin(),wordList.end());
        q.push(beginWord);
        mpp[beginWord] = 1;
        int sz = beginWord.size();
        st.erase(beginWord);
        while(!q.empty()){
            auto word = q.front();q.pop();
            if(word == endWord) break;
            int steps = mpp[word];
            for(int i=0;i<sz;i++){
                char original = word[i];
                for(char c = 'a';c <= 'z';c++){
                    word[i] = c;
                    if(st.count(word)){
                        q.push(word);
                        st.erase(word);
                        mpp[word] = steps + 1;
                    }
                }
                word[i] = original;
            }
        }
        ans.clear();
        if(mpp.count(endWord)){
            vector<string> seq;
            seq.push_back(endWord);
            dfs(endWord,seq);
        }
        return ans;
    }
};