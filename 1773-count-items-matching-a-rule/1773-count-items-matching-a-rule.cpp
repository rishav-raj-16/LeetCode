class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int count = 0;
        
        int a ;
        if(ruleKey == "type")
            a = 0;
        if(ruleKey == "color")
            a = 1;
        if(ruleKey == "name")
            a = 2;
        
        for(int i = 0; i<items.size(); i++){
            if(items[i][a] == ruleValue)
                count++;
        }
        return count;
    }
};