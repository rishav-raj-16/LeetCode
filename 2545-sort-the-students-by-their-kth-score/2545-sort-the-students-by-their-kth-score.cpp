class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        int n = score.size(), m = score[0].size();
        vector<int> temp;
        
        for(int i = 0; i < n; i++)
            temp.push_back(score[i][k]);
        sort(temp.begin(),temp.end(),greater<int>());
        int i, j, a;
        for(i = 0; i < temp.size(); i++){
            for(j = 0; j < n; j++)
                if(temp[i] == score[j][k])
                    break;
            for(a = 0; a < m; a++)
                swap(score[i][a],score[j][a]);
        }
        return score;
    }
};