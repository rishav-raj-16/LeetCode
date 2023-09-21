class Solution {
public:
    vector<int> getStrongest(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n = nums.size(), l = 0, r = n-1;
        int mid = nums[(n-1)/2];
        
        vector<int> ans(k);
        int count = 0;
        
        while(count < k) {
            int lval = abs(nums[l] - mid);
            int rval = abs(nums[r] - mid);
            
            if(rval >= lval) {
                ans[count] = nums[r];
                r--;
            }
            else {
                ans[count] = nums[l];
                l++;
            }
            count++;
        }
        return ans;
    }
};