class Solution {
public:
    vector<int> closestDivisors(int num) {
        vector<int> ans;
        int closestDiff = INT_MAX;
        
        for (int i = sqrt(num + 2); i >= 1; i--) {
            if ((num + 1) % i == 0) {
                int j = (num + 1) / i;
                int diff = abs(i - j);
                if (diff < closestDiff) {
                    closestDiff = diff;
                    ans = {i, j};
                }
            }
            
            if ((num + 2) % i == 0) {
                int j = (num + 2) / i;
                int diff = abs(i - j);
                if (diff < closestDiff) {
                    closestDiff = diff;
                    ans = {i, j};
                }
            }
        }
        
        return ans;
    }
};
