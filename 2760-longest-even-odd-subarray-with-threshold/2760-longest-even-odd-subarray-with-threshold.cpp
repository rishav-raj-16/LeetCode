class Solution {
public:
    int longestAlternatingSubarray(vector<int>& nums, int threshold) {
        int ans = 0;
        for(int j = 0; j < nums.size(); j++) {
            if((nums[j] & 1) == 0 && nums[j] <= threshold) {
                ans = max(ans, 1);
                int k;
                for(k = j + 1; k < nums.size(); k++) {
                    if(nums[k] % 2 == nums[k - 1] % 2 || nums[k] > threshold) break;
                    // cout<<nums[k]<<" ";
                    ans = max(ans, k - j + 1);
                }
            }
        }
        return ans;
    }
};