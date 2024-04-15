class Solution {
public:
    
    Solution(){
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }
    
    int minSetSize(vector<int>& arr) {
        int n = arr.size(), m = n, ans = 0, i = 0;
        vector<int> count;
        unordered_map<int,int> mp;
        
        for(int it : arr) 
            mp[it]++;
        
        for(auto it : mp) 
            count.push_back(it.second);
        
        sort(count.begin(), count.end(), greater<int>());

        while(m > (n/2)) {
            m -= count[i];
            i++, ans++;
        }
        
        return ans;
    }
};