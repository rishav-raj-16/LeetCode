class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum =accumulate(nums.begin(),nums.end(),0);
        int left_sum = 0;
        for(int i=0 ; i<nums.size();i++){
            left_sum= left_sum + nums[i];
            sum = sum - nums[i];
            if(left_sum - sum == nums[i])
            return i;
        }
        return -1;
    }
};