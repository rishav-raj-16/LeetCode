class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int>& nums) {
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++){
            set<int> a, b;
            for(int j = 0; j <= i; j++){
                a.insert(nums[j]);
            }
            for(int k = i+1; k < nums.size(); k++){
                b.insert(nums[k]);
            }
            ans.push_back(a.size() - b.size());
        }
        return ans;
    }
};