class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        vector<pair<float,pair<int,int>>> store;

        for(int i = 0; i < arr.size() - 1; i++) {
            for(int j = i+1; j < arr.size(); j++) {
                float div = float(arr[i])/ float(arr[j]);
                store.push_back({div,{arr[i],arr[j]}});
            }
        }

        sort(store.begin(), store.end());

        pair<int, int> fraction = store[k - 1].second;
        vector<int> result = {fraction.first, fraction.second};

        return result;
    }
};
