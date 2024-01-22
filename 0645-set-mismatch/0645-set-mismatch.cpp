class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        sort(begin(nums), end(nums));
        int dupl = -1;
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] == nums[i + 1]) {
                dupl = nums[i];
                break;
            }
        }
        int sum = (nums.size() + 1) * nums.size() / 2;
        for (int i = 0; i < nums.size(); i++) {
            sum -= nums[i];
        }
        return { dupl, sum + dupl };
    }
};