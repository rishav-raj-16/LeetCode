class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size(), ans = n, j = 0;
        sort(nums.begin(), nums.end());

       nums.erase(unique(nums.begin(), nums.end()), nums.end());

        int sz = nums.size();
        for (int i = 0; i < sz; i++) {
            while (j < sz && nums[j] < nums[i] + n) j++; 
                ans = min(ans, n - j + i);
        }
        return ans;
    }
};