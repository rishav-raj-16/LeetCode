class Solution {
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] != 0) {
                    ans = max(ans, helper(grid, i, j, n, m));
                }
            }
        }

        return ans;
    }
private:
    int ans = 0;
    vector<int> r = {1, -1, 0, 0};
    vector<int> c = {0, 0, -1, 1};

    int helper(vector<vector<int>>& grid, int x, int y, int n, int m) {
        if (x < 0 || x >= n || y < 0 || y >= m || grid[x][y] == 0) return 0;
        
        int curr = grid[x][y];
        grid[x][y] = 0;
        int sum = curr;

        for (int i = 0; i < 4; i++) {
            int newX = x + r[i];
            int newY = y + c[i];
            sum = max(sum, curr + helper(grid, newX, newY, n, m));
        }

        grid[x][y] = curr;
        return sum;
    }

};