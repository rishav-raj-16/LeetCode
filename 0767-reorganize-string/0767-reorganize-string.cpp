class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,int> mp;
        
        for(auto it:s)
            mp[it]++;
        
        priority_queue<pair<int,char>> store;
        for(auto it:mp)
            store.push(make_pair(it.second,it.first));
        
        string ans;
        while(store.size() >= 2) {
            auto val1 = store.top();
            store.pop();
            auto val2 = store.top();
            store.pop();
            
            ans += val1.second;
            ans += val2.second;
            
            if(--val1.first > 0 ) 
                store.push(val1);
            if(--val2.first > 0 ) 
                store.push(val2);
            }
        if(!store.empty()) {
            auto val = store.top();
            if(val.first > 1)
            return "";
            ans += val.second;
        }
        return ans;
    }
};