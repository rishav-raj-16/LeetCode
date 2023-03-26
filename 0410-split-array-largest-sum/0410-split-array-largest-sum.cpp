class Solution {
public:
    bool blackBox(vector<int>& nums, int k, int limit){
        int n = nums.size();
        int count = 1, sum = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] > limit) return false;
            
            if(sum + nums[i] > limit){
                count++;
                sum = nums[i];
            }
            else {
                sum += nums[i];
            }
        }
        return count <= k;
    }
    
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(),nums.end());
        int high = 0, n = nums.size(), ans = low;
        for(int i = 0; i < n; i++) high += nums[i];
        
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(blackBox(nums, k, mid) == true){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
    }
};