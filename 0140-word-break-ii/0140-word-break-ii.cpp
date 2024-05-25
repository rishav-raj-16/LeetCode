class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for(string word:wordDict) {
            st.insert(word);
        }
        string curr;
        helper(0,curr,s);
        return ans;
    }
    
private:
    unordered_set<string> st;
    vector<string> ans;
    
    void helper(int i, string& curr, string& s) {
        if(i == s.size())
            ans.push_back(curr);
        
        for(int j = i; j < s.size(); j++) {
            string temp = curr;
            string word = s.substr(i, j-i+1);
            
            if(st.find(word) != st.end()) {
                if(curr != ""){
                    curr += " ";
                }
                curr += word;
                helper(j+1,curr,s);
            }
            
            curr = temp;
        }
    }
};