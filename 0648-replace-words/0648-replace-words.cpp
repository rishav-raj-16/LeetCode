class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        int n = sentence.size();
        unordered_set<string> st;
        string ans = "";
        
        for(string &ch:dictionary) {
            st.insert(ch);
        }
        
        for(int i = 0; i < n; i++) {
            if(sentence[i] == ' ') continue;
            bool flag = true;
            string temp = "";
            
            for(int j = i; j < n && sentence[j] != ' '; j++) {
                temp += sentence[j];
                
                if(st.find(temp) != st.end()) {
                    ans += temp;
                    ans += ' ';
                    while(i < n && sentence[i] != ' ')
                        i++;
                    flag = false;
                    break;
                }
            }
            if(flag) {
                ans += temp;
                ans += ' ';
                while(i < n && sentence[i] != ' ')
                    i++;
            }
        }
        ans.pop_back();
        return ans;
    }
};