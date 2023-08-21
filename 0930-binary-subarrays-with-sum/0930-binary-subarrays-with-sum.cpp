class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        int l1 = 0, l2 = 0, r = 0;
        int sum1 = 0, sum2 = 0, ans = 0;
        
        while (r < n) {
            sum1 += nums[r];
            sum2 += nums[r];
            
            while (l1 <= r && sum1 > goal) {
                sum1 -= nums[l1];
                l1++;
            }
            
            while (l2 <= r && sum2 >= goal) {
                sum2 -= nums[l2];
                l2++;
            }
            
            ans += (l2 - l1);
            
            r++;
        }
        
        return ans;
    }
};
