class Solution {
public:
    bool test(vector<int>& nums, int mid, int threshold){
    int sum = 0, n = nums.size();
    for(int i = 0; i < n; i++){
        sum += nums[i] / mid;
        if(nums[i] % mid != 0) sum += 1;
    }

    if(sum <= threshold) return true;
    return false;
}

    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1, high = *max_element(nums.begin(), nums.end());
        
        while(low < high){
            int mid = low + (high - low) / 2;
            if(test(nums, mid, threshold)){
                high = mid;
            }
            else{
                low = mid + 1;
            }
        }
        return low;
    }
};