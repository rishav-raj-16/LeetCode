class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int tm = 0;
        int cntFresh = 0, cnt = 0;
        int vis[n][m];
        queue<pair<pair<int,int>,int>> q;
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 2) {
                    q.push({{i,j},0});
                    vis[i][j] = 2;
                }
                else
                    vis[i][j] = 0;
                
                if(grid[i][j] == 1)
                    cntFresh++;
            }
        }
        
        int drow[] = {0,0,1,-1};
        int dcol[] = {1,-1,0,0};
        
        while(!q.empty()) {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int t = q.front().second;
            tm = max(tm,t);
            q.pop();
            
            for(int i = 0; i < 4; i++){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];
                
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m
                  && !vis[nrow][ncol] && grid[nrow][ncol] == 1){
                    vis[nrow][ncol] = 2;
                    q.push({{nrow,ncol},t+1});
                    cnt++;
                }
            }
        }
        return ((cnt != cntFresh)? -1 : tm);
    }
};