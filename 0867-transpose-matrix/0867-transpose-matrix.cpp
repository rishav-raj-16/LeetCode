class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int colm = matrix[0].size();
        vector<vector<int>> res ;
        for(int j = 0 ; j<colm; j++)
        { vector<int> temp;
            for(int i = 0 ; i<row; i++)
            {
                temp.push_back(matrix[i][j]);
            }
            res.push_back(temp);
        }
        return res;
    }
};