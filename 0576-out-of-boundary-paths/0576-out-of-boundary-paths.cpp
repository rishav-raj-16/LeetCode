class Solution {
private:
    int mod = 1e9 + 7;
    vector<vector<vector<int>>> dp;
    
    int solve(int m, int n, int maxMove, int row, int col) {
        // Base case 1
        if(row < 0 || col < 0 || row == m || col == n) return 1;
        // Base case 2
        if(maxMove == 0) return 0;
        
        if(dp[row][col][maxMove] != -1) return dp[row][col][maxMove];
        
        int left = solve(m, n, maxMove - 1, row, col - 1) % mod;
        int up = solve(m, n, maxMove - 1, row - 1, col) % mod;
        int right = solve(m, n, maxMove - 1, row, col + 1) % mod;
        int down = solve(m, n, maxMove - 1, row + 1, col) % mod;
        
        return dp[row][col][maxMove] = ((left + up)%mod + (right + down)%mod) % mod;
    }
    
public:
    
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        int moves = maxMove;
        dp = vector<vector<vector<int>>>(m, vector<vector<int>>(n, vector<int>(maxMove+1, -1)));
        
        return solve(m,n,maxMove,startRow,startColumn);
    }
};