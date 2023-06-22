class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        int low = nums[0], high = nums[0];
        for(auto it: nums){
            low = min(low,it);
            high = max(high,it);
        }
        
        long long ans = calculate(nums, cost, nums[0]);
        
        while(low < high){
            int mid = low + (high - low) / 2;
            long long c1 = calculate(nums,  cost, mid);
            long long c2 = calculate(nums,  cost, mid + 1);
            if(c1 < c2){
                high = mid;
                ans = c1;
            }
            else{
                low = mid + 1;
                ans = c2;
            }
        }
        return ans;
    }
    
    long long calculate(vector<int>& nums, vector<int>& cost, int x){
        long long cal = 0L;
        for(int  i = 0; i < nums.size(); i++)
            cal += (1L*cost[i] * abs(nums[i] - x));
        return cal;
    }
};
