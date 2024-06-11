class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int, int> mp;
        
        for (auto it: arr1)
            mp[it]++;
        
        arr1.clear();
        
        for (auto &it: arr2) {
            while (mp[it] > 0) {
                arr1.push_back(it);
                mp[it]--;
            }
        }
        
        vector<int> remainingElements;
        for (auto it : mp) {
            while (it.second > 0) {
                remainingElements.push_back(it.first);
                it.second--;
            }
        }
        
        sort(remainingElements.begin(), remainingElements.end());
        arr1.insert(arr1.end(), remainingElements.begin(), remainingElements.end());
        
        return arr1;
    }
};
