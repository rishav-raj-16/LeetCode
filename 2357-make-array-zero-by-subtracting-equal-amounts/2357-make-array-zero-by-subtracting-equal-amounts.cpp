class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_map<int , int > mp;
        for(auto x:nums)
            if(x!=0)
            mp[x];
        return mp.size();
    }
};