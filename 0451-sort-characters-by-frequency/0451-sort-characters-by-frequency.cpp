class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> mp;
        
        for(auto it:s)
            mp[it]++;
        
        priority_queue<pair<int,char>> q;
        for(auto it:mp) 
            q.push({it.second,it.first});
        
        s = "";
        
        while(!q.empty()) {
            auto it = q.top();
            q.pop();
            for(auto i = 0; i < it.first; i++) {
                s += it.second;
            }
        }
        return s;
    }
};