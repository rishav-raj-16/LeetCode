class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string> st(wordList.begin(),wordList.end());
        if(st.find(endWord) == st.end()) return 0;
        
        queue<pair<string,int>> q;
        q.push({beginWord,1});
        
        while(!q.empty()) {
            string word = q.front().first;
            int l = q.front().second;
            q.pop();
            
            if(word == endWord) return l;
            
            for(int i = 0; i < word.size(); i++) {
                char ch = word[i];
                for(char c = 'a'; c <= 'z'; c++) {
                    if(word[i] == c) continue;
                    word[i] = c;
                    if(st.find(word) != st.end()) {
                        q.push({word,l+1});
                        st.erase(word);
                    }
                }
                word[i] = ch;
            }
        }
        
        return 0;
    }
};