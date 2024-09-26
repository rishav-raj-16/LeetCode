class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<char,int> mp {{'a',-1},{'b',-1},{'c',-1}};
        int cnt = 0;
        for(int i = 0; i < s.size(); i++) {
            mp[s[i]] = i;

            int mnpos = min({mp['a'],mp['b'],mp['c']});

            cnt += mnpos+1; 
        }
        return cnt;
    }
};