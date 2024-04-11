class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        
        for (char c : num) {
            while (k > 0 && !st.empty() && st.top() > c) {
                st.pop();
                k--;
            }
            st.push(c);
        }

        while (k > 0) {
            st.pop();
            k--;
        }
        
        num = "";
        while (!st.empty()) {
            num += st.top();
            st.pop();
        }
        
        while (!num.empty() && num.back() == '0') {
            num.pop_back();
        }
        reverse(num.begin(), num.end());
        
        return num.empty() ? "0" : num;
    }
};
