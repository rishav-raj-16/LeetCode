class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int low = 0, high = nums.size()-1;
        int start_Idx = search(nums, low, high, target);
        int end_Idx = search(nums, low, high, target + 1) - 1;
        if(start_Idx < nums.size() && nums[start_Idx] == target){
            return {start_Idx, end_Idx};
        }
        return {-1, -1};
    }

private:
    int search(vector<int>& nums, int low, int high, int target){
        while(low <= high){
            int mid = (low + high) >> 1;
            if(nums[mid] < target){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return low;
    }
};