class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        
        if(n == 1) return nums;
        
        for(int i = 0; i < n ; i++){
            int k = nums[i];
            ans.push_back(nums[k]);
        }
        return ans;
    }
};