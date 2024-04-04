class Solution {
public:
    int maxDepth(string s) {
        int ans = 0, temp = 0;
        stack<char> st;
        
        for(int i = 0 ; i < s.size(); i++) {
            if(s[i] == '(') {
                st.push(s[i]);
                temp++;
            } else if(s[i] == ')') {
                ans = max(ans,temp);
                st.pop();
                temp--;
            }
        }
        return ans;
    }
};