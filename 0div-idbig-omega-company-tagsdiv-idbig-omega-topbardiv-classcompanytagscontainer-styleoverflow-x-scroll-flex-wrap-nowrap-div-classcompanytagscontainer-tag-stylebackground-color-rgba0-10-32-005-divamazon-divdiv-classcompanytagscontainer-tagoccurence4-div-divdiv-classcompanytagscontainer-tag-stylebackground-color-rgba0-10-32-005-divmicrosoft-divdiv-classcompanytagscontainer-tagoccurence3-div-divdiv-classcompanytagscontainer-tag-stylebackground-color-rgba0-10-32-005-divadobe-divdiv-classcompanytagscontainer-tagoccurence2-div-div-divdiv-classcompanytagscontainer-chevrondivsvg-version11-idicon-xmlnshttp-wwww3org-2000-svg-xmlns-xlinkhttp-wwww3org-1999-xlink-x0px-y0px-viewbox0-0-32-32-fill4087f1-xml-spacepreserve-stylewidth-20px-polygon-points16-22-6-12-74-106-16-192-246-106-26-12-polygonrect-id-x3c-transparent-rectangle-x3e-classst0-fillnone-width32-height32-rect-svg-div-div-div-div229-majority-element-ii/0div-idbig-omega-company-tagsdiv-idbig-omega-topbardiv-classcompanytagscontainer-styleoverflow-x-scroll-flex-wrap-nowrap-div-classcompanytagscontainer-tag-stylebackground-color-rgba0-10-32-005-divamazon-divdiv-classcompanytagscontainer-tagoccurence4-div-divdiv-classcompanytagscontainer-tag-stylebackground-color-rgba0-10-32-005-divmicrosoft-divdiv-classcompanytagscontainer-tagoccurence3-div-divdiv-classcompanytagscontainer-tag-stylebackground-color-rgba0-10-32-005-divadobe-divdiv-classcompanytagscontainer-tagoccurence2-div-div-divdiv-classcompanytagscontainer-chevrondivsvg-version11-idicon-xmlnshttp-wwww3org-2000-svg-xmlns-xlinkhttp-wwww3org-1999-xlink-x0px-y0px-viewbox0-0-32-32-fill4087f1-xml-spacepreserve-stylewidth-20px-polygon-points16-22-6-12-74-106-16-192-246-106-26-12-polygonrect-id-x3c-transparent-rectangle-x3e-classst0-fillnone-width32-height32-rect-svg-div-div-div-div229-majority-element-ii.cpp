class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int maxCount = nums.size()/3;
        unordered_map<int,int> mp;
        vector<int> ans;
        
        for(auto it:nums) {
            mp[it]++;
        }
        
        for(auto it:mp) {
            if(it.second > maxCount)
                ans.push_back(it.first);
        }
        
        return ans;
    }
};