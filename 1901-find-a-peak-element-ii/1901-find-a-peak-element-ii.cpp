class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        
        int left = 0, right = n - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            int maxRowIdx = 0;
            for (int i = 0; i < m; i++) {
                if (mat[i][mid] > mat[maxRowIdx][mid]) {
                    maxRowIdx = i;
                }
            }
            
            if (mid - 1 >= left && mat[maxRowIdx][mid - 1] > mat[maxRowIdx][mid]) {
                right = mid - 1;
            }
            else if (mid + 1 <= right && mat[maxRowIdx][mid + 1] > mat[maxRowIdx][mid]) {
                left = mid + 1;
            }
            else {
                return {maxRowIdx, mid};
            }
        }
        
        return {-1, -1};
    }
};
