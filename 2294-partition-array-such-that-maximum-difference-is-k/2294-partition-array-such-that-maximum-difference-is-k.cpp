class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int ans = 1;
        
        int j = 0;
        for(int i = 0; i<nums.size();){
            if(nums[i] - nums[j] <= k)
                i++;
                
            else if(nums[i] - nums[j] > k){
                ans++;
                j = i;
                i++;
            }
        }
        
        return ans;
    }
};