class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        
        if(n == 1) return {0};
        
        vector<int> left(n,0), right(n,0);
        // submission of left
        for(int i = 1; i < n; i++){
            left[i] = left[i-1]+nums[i-1];
        }
        // submission of right
        for(int i = n-2; i >= 0; i--){
            right[i] = right[i+1]+nums[i+1];
        }
        
        vector<int> ans;
        for(int i = 0; i < n; i++){
            ans.push_back(abs(left[i] - right[i]));
        }
        return ans;
    }
};