class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low = 0, high = 0;
        for (auto it : weights) {
            high += it;
            low = max(low, it);
        }

        while (low < high) {
            int mid = low + (high - low) / 2;
            if (check(weights, days, mid))
                high = mid;
            else
                low = mid + 1;
        }
        return low;
    }

    bool check(vector<int>& weights, int days, int x) {
        int count = 1;
        int cumulativeWeight = 0;
        for (int i = 0; i < weights.size(); i++) {
            cumulativeWeight += weights[i];
            if (cumulativeWeight > x) {
                count++;
                cumulativeWeight = weights[i];
            }
        }
        return count <= days;
    }
};
