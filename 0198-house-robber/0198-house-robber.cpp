class Solution {
private:
    int fun(int idx, vector<int> &nums, vector<int> &dp){
        int n = nums.size();
        if(idx < 0) return 0;
        if(idx == 0) return nums[idx];
        
        if(dp[idx] != -1) return dp[idx];
        
        int pick = nums[idx] + fun(idx-2,nums,dp);
        int notPick = fun(idx-1,nums,dp);
        
        return dp[idx] = max(pick, notPick);
    }
    
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1,-1); 
        
        return fun(n-1,nums,dp);
    }
};