class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> prefixSum;
        prefixSum[0] = 1;
        int sum = 0, cnt = 0;
        
        for(int i:nums) {
            sum+=i;
            if(prefixSum.find(sum-k) != prefixSum.end()) {
                cnt += prefixSum[sum-k];
            }
            prefixSum[sum]++;
        }
        return cnt;
    }
};