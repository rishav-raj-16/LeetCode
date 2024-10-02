class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        map<int,int> mp;
        
        for(auto it:arr)
            mp[it] = 0;
        
        int i = 1;
        for(auto &it:mp){
            it.second = i++;
        }
        
        for(auto &it:arr){
            it = mp[it];
        }
        return arr;
    }
};