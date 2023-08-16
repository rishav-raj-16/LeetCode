class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> store;
        long long ans = 0;
        
        for(auto it:nums)
            store.push(it);
        
        
        for(int i = 0; i < k; i++){
            long long j = store.top();
            store.pop();
            ans += j;
            j = ceil(j/3.0);
            store.push(j);
        }
        return ans;
    }
};