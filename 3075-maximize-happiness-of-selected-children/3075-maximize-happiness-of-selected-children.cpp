class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        long long ans = 0;
        int dec = 0, i = 0;
        
        sort(happiness.rbegin(),happiness.rend());
        
        while(i < happiness.size() && k && happiness[i] - dec > 0) {
            ans += happiness[i] - dec;
            i++, dec++, k--;
        }
        return ans;
    }
};