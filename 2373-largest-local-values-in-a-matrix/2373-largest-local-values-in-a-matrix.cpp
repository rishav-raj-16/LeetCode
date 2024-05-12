class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size()-2;
        vector<vector<int>> ans(n,vector<int>(n));
        
        for(int row = 0; row < n; row++) {
            for(int col = 0; col < n; col++) {
                ans[row][col] = findMax(grid,row,col);
            }
        }
        return ans;
    }
    
private:
    int findMax(vector<vector<int>>& grid, int& row, int& col) {
        int res = 0;
        
        for(int i = row; i <= row+2; i++) {
            for(int j = col; j <= col+2; j++) {
                res = max(res,grid[i][j]);
            }
        }
        return res;
    }
};