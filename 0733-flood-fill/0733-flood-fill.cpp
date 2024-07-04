class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int n = image.size();
        int m = image[0].size();
        queue<pair<int,int>> q;
        vector<vector<int>> vis(n, vector<int>(m,0));
        int curr = image[sr][sc];
        q.push({sr,sc});
        
        while(!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            image[row][col] = newColor;
            vis[row][col] = 1;
            int delRow[] = {-1,0,1,0};
            int delCol[] = {0,1,0,-1};
            
            for(int j = 0; j<4; j++) {
                int nrow = row + delRow[j];
                int ncol = col + delCol[j];

                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && image[nrow][ncol] == curr && vis[nrow][ncol] == 0) {
                    image[nrow][ncol] = newColor;
                    q.push({nrow,ncol});
                }
            }
        }
        
        return image;
    }
};