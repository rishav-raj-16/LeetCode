class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        vector<vector<int>> vis(n,vector<int>(m,0)); 
        
        for(int row = 0; row < n; row++) {
            if(grid[row][0] == 1)
                dfs(row,0,grid,vis);
            if(grid[row][m-1] == 1)
                dfs(row,m-1,grid,vis);
        }
        for(int col = 0; col < m; col++) {
            if(grid[0][col] == 1)
                dfs(0,col,grid,vis);
            if(grid[n-1][col] == 1)
                dfs(n-1,col,grid,vis);
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1 && !vis[i][j])
                    ans++;
            }
        }   
        return ans;
    }
    
private:
    int drow[4] = {0,0,-1,1};
    int dcol[4] = {-1,1,0,0};
    
    void dfs(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& vis){
        int n = grid.size();
        int m = grid[0].size();
        vis[row][col] = 1;
        
        for(int i = 0; i < 4; i++) {
            int nrow = row + drow[i];
            int ncol = col + dcol[i];
            
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m
            && grid[nrow][ncol] && !vis[nrow][ncol])
                dfs(nrow,ncol,grid,vis);
        }
    }
};