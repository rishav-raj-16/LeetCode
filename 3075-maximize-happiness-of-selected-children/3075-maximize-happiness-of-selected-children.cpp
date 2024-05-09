class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
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