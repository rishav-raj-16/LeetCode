class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int> mp;
        for(auto it: arr) {
            mp[it]++;
        }

        vector<int> count;
        for(auto it: mp) {
            count.push_back(it.second);
        }
        sort(count.begin(),count.end());
        int ans = count.size();
        
        for(auto it:count) {
            if(k>=it){
                k -= it;
                ans--;
            }
        }

        return ans;
    }
};