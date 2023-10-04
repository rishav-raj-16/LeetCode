class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& nums) {
        int n = nums.size();
        vector<long long> ans(n);
        priority_queue<int> q;
        for(int i = 0; i < n; i++) {
            q.push(nums[i]);
            ans[i] = nums[i] + q.top();
            if(i == 0) continue;
            ans[i] += ans[i-1];
        }
        return ans;
    }
};