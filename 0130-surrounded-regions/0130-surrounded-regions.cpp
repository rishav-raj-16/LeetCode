class Solution {
public:
    void solve(vector<vector<char>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0)); 
        
        for(int row = 0; row < n; row++) {
            if(mat[row][0] == 'O')
                dfs(row,0,mat,vis);
        }
        for(int row = 0; row < n; row++) {
            if(mat[row][m-1] == 'O')
                dfs(row,m-1,mat,vis);
        }
        for(int col = 0; col < m; col++) {
            if(mat[0][col] == 'O')
                dfs(0,col,mat,vis);
        }
        for(int col = 0; col < m; col++) {
            if(mat[n-1][col] == 'O')
                dfs(n-1,col,mat,vis);
        }
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(mat[i][j] == 'O' && !vis[i][j])
                    mat[i][j] = 'X';
            }
        }   
    }
    
private:
    int drow[4] = {0,0,-1,1};
    int dcol[4] = {-1,1,0,0};
    
    void dfs(int row, int col, vector<vector<char>>& mat, vector<vector<int>>& vis){
        int n = mat.size();
        int m = mat[0].size();
        vis[row][col] = 1;
        
        for(int i = 0; i < 4; i++) {
            int nrow = row + drow[i];
            int ncol = col + dcol[i];
            
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m
            && mat[nrow][ncol] == 'O' && !vis[nrow][ncol])
                dfs(nrow,ncol,mat,vis);
        }
    }
};