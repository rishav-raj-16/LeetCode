class Solution {
public:
    int countBinarySubstrings(string s) {
        int ans = 0;
        int prevCount = 0;
        int currentCount = 1;  // Initialize with 1 to count the first character

        for (int i = 1; i < s.length(); i++) {
            if (s[i] == s[i - 1]) {
                currentCount++;
            } else {
                prevCount = currentCount;
                currentCount = 1;
            }

            if (prevCount >= currentCount) {
                ans++;
            }
        }

        return ans;
    }
};
