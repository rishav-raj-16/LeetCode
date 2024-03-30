class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return helper(nums, k) - helper(nums, k-1);
    }
private:
    int helper(vector<int>& nums, int k) {
        int l = 0, r = 0, n = nums.size();
        int cnt = 0;
        map<int,int> mp;
        
        while(r < n) {
            mp[nums[r]]++;
            
            while(mp.size() > k) {
                mp[nums[l]]--;
                if(mp[nums[l]] == 0) 
                    mp.erase(nums[l]);
                l++;
            }
            
            cnt += (r-l+1);
            r++;
        }
        return cnt;
    }
};