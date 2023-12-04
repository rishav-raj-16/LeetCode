class Solution {
public:
    string largestGoodInteger(string nums) {
        int ans = -1;
        
        for(int i = 0; i < nums.size() - 2; i++) {
            if(nums[i] == nums[i+1] && nums[i] == nums[i+2]) {
                ans = max(ans,nums[i] - '0');
            }
        }
        if(ans == -1)
            return "";
        return string(3,'0' + ans);
    }
};