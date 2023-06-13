class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> reverse(n, vector<int>(n));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++)
                reverse[j][i] = grid[i][j];
        }
        
        int ans = 0;
        for(auto it: grid){
            for(auto x: reverse)
                if(it == x)
                    ans++;
        }
        return ans;
    }
};