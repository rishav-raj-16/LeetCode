class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int ans = -1;
        for(int i = 0; i < nums.size()-1; i++){
            for(int j = i+1; j < nums.size(); j++) {
                if(nums[i] + nums[j] == 0)
                    ans = max(ans,abs(nums[i]));
            }
        }
        return ans;
    }
};