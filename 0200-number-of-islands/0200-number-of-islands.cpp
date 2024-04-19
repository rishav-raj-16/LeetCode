class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == '1'){
                    helper(grid,i,j);
                    ans++;
                }
            }
        }
        return ans;
    }
    
private:
    
    void helper(vector<vector<char>>& grid, int i, int j) {
        int n = grid.size(), m = grid[0].size();
        if(i < 0 || i >= n || j < 0 || j >= m || grid[i][j] != '1')
            return;
        
        grid[i][j] = '*';
        
        helper(grid,i+1,j);
        helper(grid,i-1,j);
        helper(grid,i,j+1);
        helper(grid,i,j-1);
    }
};