class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        if (nums.empty()) return {};

        sort(nums.begin(), nums.end()); // Sort the input array
    
        int n = nums.size();
        vector<int> count(n, 0);
        vector<int> prevIndex(n, -1); 
        
        int maxCount = 0;
        int maxIndex = 0;
        
        for (int i = 0; i < n; ++i) {
            for (int j = i - 1; j >= 0; --j) {
                if (nums[i] % nums[j] == 0 && count[j] > count[i]) {
                    count[i] = count[j];
                    prevIndex[i] = j;
                }
            }
            count[i]++;
            if (count[i] > maxCount) {
                maxCount = count[i];
                maxIndex = i;
            }
        }
    
        vector<int> result;
        while (maxIndex != -1) {
            result.push_back(nums[maxIndex]);
            maxIndex = prevIndex[maxIndex];
        }
    
        return result;
    }
};