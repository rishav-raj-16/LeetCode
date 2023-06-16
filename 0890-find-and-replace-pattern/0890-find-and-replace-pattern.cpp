class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        for(auto it: words){
            if(check(it, pattern))
                ans.push_back(it);
        }
        return ans;
    }
    
    bool check(string s, string p){
        unordered_map<char,char> mp;
        set<char> temp;
        for(int i = 0; i < p.size(); i++){
            if(mp.find(p[i]) == mp.end() && temp.find(s[i]) == temp.end()){
                mp[p[i]] = s[i];
                temp.insert(s[i]);
            }
            else {
                if(mp[p[i]] != s[i])
                    return false;
                else
                    continue;
            }
        }
        return true;
    }
};