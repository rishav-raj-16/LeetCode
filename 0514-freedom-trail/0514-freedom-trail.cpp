class Solution {
public:
    int findRotateSteps(string& ring, string& key) {
        vector<vector<int>> dp(101,vector<int>(101,INT_MAX));
        return solve(0,0,ring,key,dp);
    }
    
private:
    int count(int ringIndx, int i, int len) {
        int dist = abs(ringIndx - i);
        int wrap = len - dist;
        return min(dist,wrap);
    }
    
    int solve(int ringIndx, int keyIndx, string& ring, string& key,vector<vector<int>>& dp) {
        if(keyIndx == key.size()) return 0;
        
        if(dp[ringIndx][keyIndx] != INT_MAX) {
            return dp[ringIndx][keyIndx];
        }
        int res = INT_MAX;
        for(int i = 0; i < ring.size(); i++) {
            if(ring[i] == key[keyIndx]) {
                int steps = 1 + count(ringIndx,i,ring.size());
                int totalCount = steps + solve(i, keyIndx+1, ring, key, dp);
                res = min(res, totalCount);
            }
        }
        
        dp[ringIndx][keyIndx] = res;
        
        return dp[ringIndx][keyIndx];
    }
};