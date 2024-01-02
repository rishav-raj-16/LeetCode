class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<vector<int>> ans;
        unordered_map<int, int> count;

        for (auto num : nums)
            count[num]++;

        while (!count.empty()) {
            vector<int> row;
            for (auto it = count.begin(); it != count.end(); ) {
                row.push_back(it->first);
                if (--(it->second) == 0) {
                    it = count.erase(it);
                } else {
                    ++it;
                }
            }
            ans.push_back(row);
        }
        return ans;
    }
};
