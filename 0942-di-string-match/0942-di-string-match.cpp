class Solution {
public:
    vector<int> diStringMatch(string s) {
        int i = 0, j = s.size();
        vector<int> ans;
        
        for(auto it: s){
            if(it == 'I'){
                ans.push_back(i++);
            }
            else{
                ans.push_back(j--);
            }
        }
        ans.push_back(i++);
        return ans;
    }
};