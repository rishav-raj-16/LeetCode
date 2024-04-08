class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        unordered_map<int,int> mp;
        
        for(int it:students) {
            mp[it]++;
        }
        
        int ans = sandwiches.size();
        for(int i = 0; i < sandwiches.size(); i++) {
            if(mp[sandwiches[i]] == 0) break;
            mp[sandwiches[i]]--;
            ans--;
        }
        return ans;
    }
};