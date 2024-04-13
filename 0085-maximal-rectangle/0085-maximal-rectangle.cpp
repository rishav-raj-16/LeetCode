class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<int> num(m, 0);
        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == '0')
                    num[j] = 0;
                else
                    num[j]++;
            }

            int temp = helper(num, m);
            ans = max(ans, temp);
        }
        return ans;
    }

private:
    int helper(vector<int>& histo, int n) {
        stack<int> st;
        int ans = 0;

        for (int i = 0; i <= n; i++) {
            while (!st.empty() && (i == n || histo[st.top()] >= histo[i])) {
                int temp = histo[st.top()];
                st.pop();
                int wid;
                if (st.empty())
                    wid = i;
                else
                    wid = i - st.top() - 1;
                ans = max(ans, temp * wid);
            }
            st.push(i);
        }
        return ans;
    }
};
