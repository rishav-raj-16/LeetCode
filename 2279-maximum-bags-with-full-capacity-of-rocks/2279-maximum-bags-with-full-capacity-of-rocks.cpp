class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n = capacity.size();
        vector<int> rocks_needed(n);
        for (int i = 0; i < n; ++i) {
            rocks_needed[i] = max(0, capacity[i] - rocks[i]);
        }

        vector<int> sorted_bags(n);
        for (int i = 0; i < n; ++i) {
            sorted_bags[i] = i;
        }
        sort(sorted_bags.begin(), sorted_bags.end(), [&](int i, int j) {
            return rocks_needed[i] < rocks_needed[j];
        });

        
        int full_capacity_bags = 0;
        for (int i : sorted_bags) {
            if (additionalRocks == 0) {
                break;
            }

            int rocks_to_add = std::min(additionalRocks, capacity[i] - rocks[i]);
            rocks[i] += rocks_to_add;
            additionalRocks -= rocks_to_add;

            if (rocks[i] == capacity[i]) {
                full_capacity_bags++;
            }
        }

        return full_capacity_bags;
    }
};

