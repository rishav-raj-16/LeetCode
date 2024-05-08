class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        unordered_map<int, string> mp{
            {1, "Gold Medal"},
            {2, "Silver Medal"},
            {3, "Bronze Medal"}
        };

        vector<pair<int, int>> indexedScores;
        for (int i = 0; i < score.size(); ++i) {
            indexedScores.push_back({score[i], i});
        }
        sort(indexedScores.rbegin(), indexedScores.rend());

        vector<string> ans(score.size());
        for (int i = 0; i < indexedScores.size(); ++i) {
            int position = indexedScores[i].second;
            if (i < 3) {
                ans[position] = mp[i + 1]; 
            } else {
                ans[position] = to_string(i + 1);
            }
        }

        return ans;
    }
};