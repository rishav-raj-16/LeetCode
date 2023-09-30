class Solution {
public:
  bool find132pattern(vector<int>& nums) {
    int n = nums.size();
    if (n < 3) {
      return false; // The pattern requires at least 3 elements.
    }

    vector<int> min_values(n);
    min_values[0] = nums[0];

    // Compute the minimum value for each element in nums.
    for (int i = 1; i < n; i++) {
      min_values[i] = min(min_values[i - 1], nums[i]);
    }

    stack<int> stk;

    for (int j = n - 1; j >= 0; j--) {
      // Check for the "32" part of the pattern.
      if (nums[j] > min_values[j]) {
        while (!stk.empty() && stk.top() <= min_values[j]) {
          stk.pop();
        }
        if (!stk.empty() && stk.top() < nums[j]) {
          return true;
        }
        stk.push(nums[j]);
      }
    }

    return false;
  }
};