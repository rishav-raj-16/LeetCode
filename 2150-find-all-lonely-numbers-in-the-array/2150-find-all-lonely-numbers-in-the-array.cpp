class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        unordered_map<int,int> count;
        vector<int> ans;
        
        for(auto it:nums)
            count[it]++;
        
        for(auto it:count){
            if(it.second == 1){
                if(count.find(it.first+1) == count.end() && count.find(it.first-1) == count.end())
                    ans.push_back(it.first);
            }
        }
        return ans;
    }
};