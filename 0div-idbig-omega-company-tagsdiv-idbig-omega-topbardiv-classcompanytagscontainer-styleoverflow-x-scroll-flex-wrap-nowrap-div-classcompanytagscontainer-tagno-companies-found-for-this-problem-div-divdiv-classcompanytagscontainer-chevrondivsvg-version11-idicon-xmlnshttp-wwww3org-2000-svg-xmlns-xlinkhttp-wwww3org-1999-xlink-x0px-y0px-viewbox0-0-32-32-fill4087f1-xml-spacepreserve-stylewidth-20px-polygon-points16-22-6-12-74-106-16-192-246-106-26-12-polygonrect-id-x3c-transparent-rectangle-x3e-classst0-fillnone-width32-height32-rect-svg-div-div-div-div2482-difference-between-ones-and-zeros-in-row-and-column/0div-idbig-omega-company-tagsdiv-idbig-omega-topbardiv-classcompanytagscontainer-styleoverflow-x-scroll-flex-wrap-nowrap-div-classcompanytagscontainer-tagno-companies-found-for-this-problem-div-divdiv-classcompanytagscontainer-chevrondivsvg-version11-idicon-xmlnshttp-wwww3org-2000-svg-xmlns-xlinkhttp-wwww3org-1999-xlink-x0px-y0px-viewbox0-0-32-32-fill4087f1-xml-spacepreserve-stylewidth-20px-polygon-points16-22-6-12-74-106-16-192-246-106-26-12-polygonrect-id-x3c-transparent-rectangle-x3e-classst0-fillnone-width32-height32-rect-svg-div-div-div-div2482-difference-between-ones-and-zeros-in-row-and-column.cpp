class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> ans(m, vector<int> (n , 0));
        
        vector<int> countOneInRows, countOneInCols, countZeroInRows, countZeroInCols;
        
        for(int i = 0; i < m; i++) {
            int countOne = 0, countZero = 0;
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1)
                    countOne++;
                else
                    countZero++;
            }
            countOneInRows.push_back(countOne);
            countZeroInRows.push_back(countZero);
        }

        for(int i = 0; i < n; i++) {
            int countOne = 0, countZero = 0;
            for(int j = 0; j < m; j++) {
                if(grid[j][i] == 1)
                    countOne++;
                else
                    countZero++;
            }
            countOneInCols.push_back(countOne);
            countZeroInCols.push_back(countZero);
        }

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                ans[i][j] = countOneInRows[i] + countOneInCols[j] - countZeroInRows[i] - countZeroInCols[j]; 
            }
        }
        return ans;
    }
};