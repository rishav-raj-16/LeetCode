class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        vector<int> ans;
        int row = mat.size(), col = mat[0].size();
        int count = 0, total = row * col;
        
        int strow = 0, stcol = 0;            // st = starting
        int endrow = row - 1, endcol = col - 1;
        
        while(count < total){
            for(int i = stcol; count < total && i <= endcol; i++){
                ans.push_back(mat[strow][i]);
                count++;
            }
            strow++;
            for(int i = strow; count < total && i <= endrow; i++){
                ans.push_back(mat[i][endcol]);
                count++;
            }
            endcol--;
            for(int i = endcol; count < total && i >= stcol; i--){
                ans.push_back(mat[endrow][i]);
                count++;
            }
            endrow--;
            for(int i = endrow; count < total && i >= strow; i--){
                ans.push_back(mat[i][stcol]);
                count++;
            }
            stcol++;
        }
        return ans;
    }
};