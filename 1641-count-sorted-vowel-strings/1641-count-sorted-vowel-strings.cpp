class Solution {
public:
    int solve(int n, int i, vector<vector<int>>& dp) {
        if(n == 0) {
            return 1;
        }
        
        if(i == 5) {
            return 0;
        }
        
        if(dp[n][i] != -1) {
            return dp[n][i];
        }
        
        return dp[n][i] = solve(n-1,i,dp) + solve(n,i+1,dp);
    }
    
    int countVowelStrings(int n) {
        vector<vector<int>> dp(n+1,vector<int> (5,-1));
        return solve(n,0,dp);
    }
};