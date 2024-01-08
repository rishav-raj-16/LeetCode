using ll = long long;
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        vector<map<ll,int>> dp(n);
        
        for(int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                ll diff = ll(nums[i]) - ll(nums[j]);
                ll temp = 0;
                
                if(dp[j].find(diff) != dp[j].end()){
                    temp = dp[j][diff];
                }

                ans += temp;
                dp[i][diff] += temp + 1;
            }
        }
        return ans;
    }
};