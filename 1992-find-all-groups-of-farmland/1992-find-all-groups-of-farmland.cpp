class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int n = land.size(), m = land[0].size();
        vector<vector<int>> ans;
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m ; j++){
                if(land[i][j] == 1) {
                    int r = i, c = j;
                    
                    while(r < n && land[r][j] == 1) r++;
                    while(c < m && land[i][c] == 1) c++;
                    
                    helper(land,i,j,r,c);
                    
                    ans.push_back({i,j,r-1,c-1});
                }
            }
        }
        return ans;
    }
    
private:
    
    void helper(vector<vector<int>>& land, int a, int b, int r, int c) {
        for(int i = a; i < r; i++) {
            for(int j = b; j < c; j++) {
                land[i][j] = -1;
            }
        }
    }
};