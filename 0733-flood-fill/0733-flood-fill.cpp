class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if(image[sr][sc] == newColor) return image;
        int n = image.size();
        int m = image[0].size();
        queue<pair<int,int>> q;
        int curr = image[sr][sc];
        q.push({sr,sc});
        
        while(!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            image[row][col] = newColor;
            
            int delRow[] = {-1,0,1,0};
            int delCol[] = {0,1,0,-1};
            
            for(int j = 0; j<4; j++) {
                int nrow = row + delRow[j];
                int ncol = col + delCol[j];

                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && image[nrow][ncol] == curr) {
                    image[nrow][ncol] = newColor;
                    q.push({nrow,ncol});
                }
            }
        }
        
        return image;
    }
};