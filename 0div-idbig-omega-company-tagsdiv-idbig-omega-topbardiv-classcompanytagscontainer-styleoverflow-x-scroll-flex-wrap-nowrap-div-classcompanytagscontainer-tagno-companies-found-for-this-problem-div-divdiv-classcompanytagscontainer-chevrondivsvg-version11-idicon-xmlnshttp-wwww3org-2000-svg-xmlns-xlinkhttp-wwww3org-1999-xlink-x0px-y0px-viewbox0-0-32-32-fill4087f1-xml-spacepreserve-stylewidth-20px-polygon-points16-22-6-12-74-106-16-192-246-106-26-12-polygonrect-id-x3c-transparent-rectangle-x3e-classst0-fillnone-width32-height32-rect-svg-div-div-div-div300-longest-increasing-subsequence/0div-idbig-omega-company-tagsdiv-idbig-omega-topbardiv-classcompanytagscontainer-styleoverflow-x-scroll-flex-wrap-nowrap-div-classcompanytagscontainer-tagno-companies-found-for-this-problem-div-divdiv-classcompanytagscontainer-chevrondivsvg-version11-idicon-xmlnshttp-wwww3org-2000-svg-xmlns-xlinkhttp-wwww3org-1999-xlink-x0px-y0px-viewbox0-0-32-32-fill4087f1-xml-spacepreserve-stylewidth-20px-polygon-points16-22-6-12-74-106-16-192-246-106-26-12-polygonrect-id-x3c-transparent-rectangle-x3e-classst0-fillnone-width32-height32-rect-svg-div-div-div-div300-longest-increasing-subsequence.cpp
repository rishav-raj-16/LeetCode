class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> temp;
        int ans = 1;
        
        temp.push_back(nums[0]);
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] > temp.back()) {
                temp.push_back(nums[i]);
                ans++;
            } else {
                int indx = lower_bound(temp.begin(), temp.end(), nums[i]) - temp.begin();
                temp[indx] = nums[i];
            }
        }
        return ans;
    }
};