class Solution {
public:
    int minMoves(vector<int>& nums) {
        int ans = 0;
        int mn = nums[0];
        
        for (int num : nums) {
            mn = min(mn, num);
        }
        
        for (int num : nums) {
            ans += (num - mn);
        }
        
        return ans;
    }
};
