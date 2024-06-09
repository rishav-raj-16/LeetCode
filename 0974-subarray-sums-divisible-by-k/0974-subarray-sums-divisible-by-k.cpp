class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int ans = 0, sum = 0;
        unordered_map<int,int> mp;

        mp[0] = 1;

        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];

            int rem = sum % k;
            rem = (rem < 0) ? rem + k : rem;

            if(mp[rem]) 
                ans += mp[rem];
            
            mp[rem]++;
        }
        return ans;
    }
};