class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> current;
        findSubsets(nums, 0, current, ans);
        return ans;
    }
    
private:
    void findSubsets(vector<int>& nums, int index, vector<int>& current, vector<vector<int>>& result) {
        if (index == nums.size()) {
            result.push_back(current);
            return;
        }
        current.push_back(nums[index]);
        findSubsets(nums, index + 1, current, result);
        current.pop_back();
        findSubsets(nums, index + 1, current, result);
    }
};