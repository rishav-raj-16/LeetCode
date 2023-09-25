class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m = box.size(), n = box[0].size();
        vector<vector<char>> ans(n, vector<char>(m, '.'));

        for (int i = 0; i < m; i++) {
            int stonePos = n - 1; 

            for (int j = n - 1; j >= 0; j--) {
                char currentCell = box[i][j];

                if (currentCell == '#') {
                    ans[stonePos][m - i - 1] = '#';
                    stonePos--;
                } else if (currentCell == '*') {
                    stonePos = j - 1;
                    ans[j][m - i - 1] = '*';
                }
            }
        }
        return ans;
    }
};
