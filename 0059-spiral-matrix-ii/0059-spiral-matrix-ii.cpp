class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n, 0));
        int count = 0, total = n*n;
        int strow = 0, stcol = 0;            // st = starting
        int endrow =n-1, endcol =n-1;
        
        while(count < total){
            for(int i = stcol; count < total && i <= endcol; i++){
                ans[strow][i] = ++count;
            }
            strow++;
            for(int i = strow; count < total && i <= endrow; i++){
                ans[i][endcol] = ++count;
            }
            endcol--;
            for(int i = endcol; count < total && i >= stcol; i--){
                ans[endrow][i] = ++count;
            }
            endrow--;
            for(int i = endrow; count < total && i >= strow; i--){
                ans[i][stcol] = ++count;
            }
            stcol++;
        }
        return ans;
    }
};