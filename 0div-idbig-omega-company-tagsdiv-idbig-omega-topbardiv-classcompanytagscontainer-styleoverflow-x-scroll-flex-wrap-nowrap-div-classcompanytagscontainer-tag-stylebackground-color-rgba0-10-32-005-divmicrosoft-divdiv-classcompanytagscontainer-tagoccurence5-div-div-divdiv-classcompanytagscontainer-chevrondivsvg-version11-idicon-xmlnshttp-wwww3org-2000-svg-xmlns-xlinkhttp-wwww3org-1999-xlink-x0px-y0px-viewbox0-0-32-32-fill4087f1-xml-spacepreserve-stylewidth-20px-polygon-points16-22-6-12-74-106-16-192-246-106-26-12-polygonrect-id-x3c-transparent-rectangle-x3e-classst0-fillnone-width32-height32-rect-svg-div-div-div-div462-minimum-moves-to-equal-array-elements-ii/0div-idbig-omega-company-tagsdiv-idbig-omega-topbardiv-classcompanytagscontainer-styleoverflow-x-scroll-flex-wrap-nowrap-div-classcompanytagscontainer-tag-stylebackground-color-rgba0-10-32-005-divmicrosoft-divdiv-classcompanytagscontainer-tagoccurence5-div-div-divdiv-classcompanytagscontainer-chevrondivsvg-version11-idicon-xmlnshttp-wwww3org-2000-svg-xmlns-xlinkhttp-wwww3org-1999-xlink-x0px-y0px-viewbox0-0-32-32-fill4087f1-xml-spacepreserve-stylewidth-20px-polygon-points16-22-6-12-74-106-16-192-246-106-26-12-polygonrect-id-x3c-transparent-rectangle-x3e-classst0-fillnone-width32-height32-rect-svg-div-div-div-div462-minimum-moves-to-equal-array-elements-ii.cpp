class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int ans = 0, n = nums.size();
        
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n/2; i++) {
            ans += nums[n-i-1] - nums[i];
        }
        return ans;
    }
};