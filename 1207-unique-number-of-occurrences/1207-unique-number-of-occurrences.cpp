class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int,int> mp;
        for(auto it : arr){
            mp[it]++;
        }
        vector<int> res;
        for(auto it : mp){
            res.push_back(it.second);
        }
        sort(res.begin(),res.end());
        for(int i = 0; i < res.size()-1; i++){
            if(res[i] == res[i+1]){
                return false;
            }
        }
        return true;
    }
};