class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        long long sum = accumulate(nums.rbegin()+1,nums.rend(),0LL);
        
        for(int i = nums.size()-1; i >= 2; i--) {
            if(sum > nums[i]){
                return sum+nums[i];
            }
            
            sum -= nums[i-1];
        }
        
        return -1;
    }
};