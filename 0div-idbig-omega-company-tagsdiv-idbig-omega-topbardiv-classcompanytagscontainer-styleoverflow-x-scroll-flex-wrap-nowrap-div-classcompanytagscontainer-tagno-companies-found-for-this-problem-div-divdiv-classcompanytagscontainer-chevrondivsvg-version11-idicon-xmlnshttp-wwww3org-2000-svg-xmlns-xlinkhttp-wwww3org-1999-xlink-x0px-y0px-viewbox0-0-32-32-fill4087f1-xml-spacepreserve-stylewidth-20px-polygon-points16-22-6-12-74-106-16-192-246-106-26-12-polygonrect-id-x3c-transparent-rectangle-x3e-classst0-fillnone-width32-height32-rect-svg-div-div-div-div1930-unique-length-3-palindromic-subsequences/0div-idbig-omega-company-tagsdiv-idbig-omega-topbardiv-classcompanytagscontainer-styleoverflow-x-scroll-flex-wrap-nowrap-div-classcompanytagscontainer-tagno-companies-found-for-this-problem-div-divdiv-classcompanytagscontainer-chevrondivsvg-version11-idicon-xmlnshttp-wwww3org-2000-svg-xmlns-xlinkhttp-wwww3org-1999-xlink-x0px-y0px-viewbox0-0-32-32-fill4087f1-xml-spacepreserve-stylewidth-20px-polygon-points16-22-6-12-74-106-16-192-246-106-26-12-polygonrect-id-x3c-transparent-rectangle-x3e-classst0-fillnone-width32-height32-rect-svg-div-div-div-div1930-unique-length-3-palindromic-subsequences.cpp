class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<int> first_ocurr(26, INT_MAX);
        vector<int> last_ocurr(26, INT_MIN);
        
        for(int i = 0; i < s.size(); i++) {
            int ch = s[i] - 'a';
            first_ocurr[ch] = min(first_ocurr[ch], i);
            last_ocurr[ch] = max(last_ocurr[ch], i);
        }
        
        int count = 0;
        
        for(int i = 0; i < 26; i++) {
            if(first_ocurr[i] == INT_MAX || last_ocurr[i] == INT_MIN) {
                continue;
            }
            
            set<char> st;
            for(int j = first_ocurr[i] + 1; j < last_ocurr[i]; j++) {
                st.insert(s[j]);
            }
            count += st.size();
        }
        return count;
    }
};