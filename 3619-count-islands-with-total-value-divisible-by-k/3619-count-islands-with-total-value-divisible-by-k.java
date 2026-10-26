class Solution {
    int[] x = {0,0,1,-1};
    int[] y = {-1,1,0,0};
    boolean[][] vis;
    int m,n;

    private long solve(int i, int j, int[][] grid) {
        long res = grid[i][j];
        vis[i][j] = true;
        for(int k = 0; k < 4; k++) {
            int r = i + x[k];
            int c = j + y[k];

            if(r < m && r >= 0 && c >= 0 && c < n && vis[r][c] == false && grid[r][c] > 0) {
                res += solve(r,c,grid);
            }
        }

        return res;
    }

    public int countIslands(int[][] grid, int k) {
        m = grid.length;
        n = grid[0].length;
        vis =  new boolean[m][n];

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) 
                vis[i][j] = false;
        }
        
        int ans = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(vis[i][j] == false && grid[i][j] > 0) {
                    long temp = solve(i,j,grid);
                    if(temp % k == 0) ans++;
                }
            }
        }
        return ans;
    }
}