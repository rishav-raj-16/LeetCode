class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int ans = 0;
        unordered_map<int,int> mp;
        
        for(int it:time){
            int mod = it % 60;
            int comp = (mod == 0) ? 0 : 60 - mod;
            if(mp.find(comp) != mp.end()){
                ans += mp[comp];
            }
            mp[mod]++;
        }

        return ans;
    }
};