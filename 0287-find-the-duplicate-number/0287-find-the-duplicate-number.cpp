class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = sizeof(nums) / sizeof(int);
        sort(nums.begin(),nums.end());
        int result;
        int size = nums.size();
        for(int i=1 ;i<size ;i++)
        {
            if(nums[i] == nums[i - 1])
            {
                result = nums[i];
            }
            else continue;
        }
        return result;
    }
};