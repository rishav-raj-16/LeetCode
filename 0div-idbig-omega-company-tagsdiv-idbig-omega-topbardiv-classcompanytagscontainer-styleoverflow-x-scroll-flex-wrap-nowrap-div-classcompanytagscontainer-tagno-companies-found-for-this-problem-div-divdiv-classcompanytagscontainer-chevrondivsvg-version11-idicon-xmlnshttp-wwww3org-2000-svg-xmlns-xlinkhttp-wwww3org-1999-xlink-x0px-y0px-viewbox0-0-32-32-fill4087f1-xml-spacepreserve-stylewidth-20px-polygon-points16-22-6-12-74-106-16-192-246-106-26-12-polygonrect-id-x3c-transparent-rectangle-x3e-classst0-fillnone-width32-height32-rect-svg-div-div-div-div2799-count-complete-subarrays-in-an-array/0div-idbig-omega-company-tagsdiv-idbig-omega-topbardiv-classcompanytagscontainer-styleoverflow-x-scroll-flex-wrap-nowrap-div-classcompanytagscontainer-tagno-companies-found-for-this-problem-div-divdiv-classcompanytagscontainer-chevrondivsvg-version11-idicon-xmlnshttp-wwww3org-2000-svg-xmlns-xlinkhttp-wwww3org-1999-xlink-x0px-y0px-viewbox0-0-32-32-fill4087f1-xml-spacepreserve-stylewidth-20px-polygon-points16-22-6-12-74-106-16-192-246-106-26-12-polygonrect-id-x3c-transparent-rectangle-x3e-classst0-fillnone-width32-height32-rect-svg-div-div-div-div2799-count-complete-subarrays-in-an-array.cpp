class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        
        int totalDistinct = distinctElements(nums);

        for (int i = 0; i < n; i++) {
            unordered_set<int> distinct;
            for (int j = i; j < n; j++) {
                distinct.insert(nums[j]);
                if (distinct.size() == totalDistinct) {
                    ans++;
                }
            }
        }

        return ans;
    }

private:
    int distinctElements(vector<int>& nums) {
        unordered_set<int> distinct;
        for (int num : nums) {
            distinct.insert(num);
        }
        return distinct.size();
    }
};
