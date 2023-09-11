class Solution {
public:
    int maximumSum(vector<int>& nums) {
        int ans = -1;
        unordered_map<int, int> maxSum;

        for (int num : nums) {
            int digitSum = digiSum(num);
            if (maxSum.count(digitSum)) {
                ans = max(ans, num + maxSum[digitSum]);
                maxSum[digitSum] = max(maxSum[digitSum], num);
            } else {
                maxSum[digitSum] = num;
            }
        }

        return ans;
    }

private:
    int digiSum(int x) {
        int res = 0;
        while (x > 0) {
            res += (x % 10);
            x /= 10;
        }
        return res;
    }
};
