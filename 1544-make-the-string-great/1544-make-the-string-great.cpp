class Solution {
public:
    string makeGood(string s) {
        stack<char> st;
        
        for (auto it : s) {
            if (!st.empty() && abs(it - st.top()) == 32) {
                st.pop();
            } else {
                st.push(it);
            }
        }
        
        s = "";
        while (!st.empty()) {
            s = st.top() + s;
            st.pop();
        }
        
        return s;
    }
};