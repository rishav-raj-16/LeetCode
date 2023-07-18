class Solution {
public:
    int findValueOfPartition(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        
        int diff = nums[1] - nums[0];
        for(int i = 0; i < nums.size()-1; i++){
            int temp = nums[i+1] - nums[i];
            cout<<temp<<" ";
            diff = min(diff,temp);
        }
        return diff;
    }
};