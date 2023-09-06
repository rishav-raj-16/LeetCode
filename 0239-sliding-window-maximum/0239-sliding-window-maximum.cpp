class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        priority_queue<pair<int, int>> maxHeap;
        
        for (int i = 0; i < k; i++) {
            maxHeap.push({nums[i], i});
        }
        
        res.push_back(maxHeap.top().first);

        for (int i = k; i < nums.size(); i++) {
            maxHeap.push({nums[i], i});
            
            while (maxHeap.top().second <= i - k) {
                maxHeap.pop();
            }
            res.push_back(maxHeap.top().first);
        }
        
        return res;
    }
};
