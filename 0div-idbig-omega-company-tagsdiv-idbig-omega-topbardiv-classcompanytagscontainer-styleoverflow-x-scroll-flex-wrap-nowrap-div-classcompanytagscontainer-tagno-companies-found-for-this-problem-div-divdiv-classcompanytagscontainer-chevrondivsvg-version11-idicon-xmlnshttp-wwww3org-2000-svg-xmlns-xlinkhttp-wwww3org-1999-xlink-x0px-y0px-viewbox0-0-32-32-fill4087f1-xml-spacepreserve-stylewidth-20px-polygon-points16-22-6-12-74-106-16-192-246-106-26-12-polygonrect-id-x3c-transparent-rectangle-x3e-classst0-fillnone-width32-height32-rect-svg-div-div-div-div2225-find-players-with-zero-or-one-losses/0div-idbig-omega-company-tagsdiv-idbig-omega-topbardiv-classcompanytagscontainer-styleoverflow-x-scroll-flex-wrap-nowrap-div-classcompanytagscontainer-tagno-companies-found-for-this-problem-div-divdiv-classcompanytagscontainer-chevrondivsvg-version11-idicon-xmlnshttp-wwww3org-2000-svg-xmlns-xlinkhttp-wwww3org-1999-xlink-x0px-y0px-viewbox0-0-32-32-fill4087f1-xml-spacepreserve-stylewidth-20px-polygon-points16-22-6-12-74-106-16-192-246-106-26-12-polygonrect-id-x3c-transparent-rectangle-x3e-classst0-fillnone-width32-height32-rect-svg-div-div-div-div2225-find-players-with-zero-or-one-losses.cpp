class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int,int> Losers;
        set<int> winners;
        vector<int> ans0, ans1;
        
        for(auto it: matches){
            winners.insert(it[0]);
            Losers[it[1]]++;
        }
        
        for(auto it: winners)
            if(Losers.find(it) == Losers.end())
                ans0.push_back(it);
        
        for(auto it: Losers)
            if(it.second == 1)
                ans1.push_back(it.first);
        
        return {ans0,ans1};
    }
};