class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int ans = 0;
        unordered_set<int> store;
        int l = 0, r = 0;
        
        int sum = 0;
        while (r < nums.size()) {
            if (store.find(nums[r]) == store.end()) {
                store.insert(nums[r]);
                sum += nums[r];
                ans = max(ans,sum);
                r++;
            } else {
                sum -= nums[l];
                store.erase(nums[l]);
                l++;
            }
        }
        
        return ans;
    }
};
