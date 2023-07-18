class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char,int> mp;
        string ans = "";
        
        for(auto it: s)
            mp[it]++;
        
        for(auto it: order){
            if(mp.find(it) != mp.end()){
                for(int i = 0; i < mp[it]; i++)
                    ans += it;
                mp.erase(it);
            }
        }
        for(auto it: mp)
            while(it.second > 0){
                ans += it.first;
                it.second--;
            }
        return ans;
    }
};