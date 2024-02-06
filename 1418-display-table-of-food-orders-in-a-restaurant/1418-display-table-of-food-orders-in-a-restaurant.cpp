class Solution {
public:
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
        vector<vector<string>> res;
        
        set<string> food;
        for(auto it : orders) food.insert(it[2]);
        
        int i = 0;
        unordered_map<string,int> foodMap; // map index of food
        for(auto it : food) {
            foodMap[it] = i;
            i++;
        }
        
        vector<int> freq(food.size(),0);
        map<int,vector<int>> mp;
        
        for(int i = 0; i<orders.size(); i++){
            int num = stoi(orders[i][1]);
            if(mp.find(num) == mp.end())
                mp[num] = freq;
            mp[num][foodMap[orders[i][2]]]++;
        }
        
        res.push_back({"Table"});
        res.back().insert(res.back().end(),food.begin(),food.end());
        
        for(auto it : mp){
            res.push_back({to_string(it.first)});
            for(auto ele : it.second){
                res.back().insert(res.back().end(),to_string(ele));
            }
        }
        
        return res;
    }
};