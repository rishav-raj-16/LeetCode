class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        
        
        for(int i = 0; i < mat.size(); i++) {
            int count = 0, j = 0;
            while(j < mat[i].size() && mat[i][j] == 1)
                count++, j++;
            q.push({count,i});
        }
        
        vector<int> ans;
        while(k > 0 && !q.empty()) {
            auto it = q.top();
            q.pop();
            ans.push_back(it.second);
            k--;
        }
        return ans;
    }
};