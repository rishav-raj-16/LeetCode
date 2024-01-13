class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char, int> mp;
        int ans = 0;
        for(auto it: s)
            mp[it]++;
        
        for(auto it: t){
            if(mp.find(it) == mp.end())
                ans++;
            else if(mp[it] == 0){
                ans++;
            }
            else
                mp[it]--;
        }
        return ans;
    }
};