class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> memo(n,vector<int>(n, INT_MAX));
        
        int result = INT_MAX;
        for(int col = 0; col < n; col++) {
                result = min(result, solve(col, 0, grid, memo));
        }
        return result;
    }

private:
    int solve(int col, int row, vector<vector<int>>& grid, vector<vector<int>>& memo) {
        int n = grid.size();
        if(row == n-1) return grid[row][col];
        
        if(memo[row][col] != INT_MAX)
            return memo[row][col];
        
        int ans = INT_MAX;
        for(int newCol = 0; newCol < n; newCol++) {
            if(newCol != col) {
                ans = min(ans,solve(newCol,row+1,grid,memo));
            }
        }
        memo[row][col] = ans + grid[row][col];
        
        return memo[row][col];
    }
};