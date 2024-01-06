class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> minCndi(n, 1);

        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i - 1])
                minCndi[i] = minCndi[i - 1] + 1;
        }

        for (int i = n - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1])
                minCndi[i] = max(minCndi[i], minCndi[i + 1] + 1);
        }

        int ans = 0;
        for (auto it : minCndi)
            ans += it;

        return ans;
    }
};
