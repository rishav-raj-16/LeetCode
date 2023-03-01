class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        set <int> row , colum;  //using set to store only unique index..
        
        for(int i = 0; i<matrix.size(); i++){
            for(int j= 0; j<matrix[0].size(); j++)
                if(matrix[i][j] == 0){
                    row.insert(i);    //storing the index where the 0 comes..
                    colum.insert(j);
                }
        }
        for(auto x : row){
            for(int j = 0; j < matrix[0].size(); j++)
                matrix[x][j] = 0;
        }
        for(auto x : colum){
            for(int i = 0; i < matrix.size(); i++)
                matrix[i][x] = 0;
        }      
    }
};