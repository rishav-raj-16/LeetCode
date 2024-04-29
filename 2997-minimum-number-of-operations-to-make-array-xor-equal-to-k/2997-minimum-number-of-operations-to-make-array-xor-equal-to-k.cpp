class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int total_xor = 0;


        for(int &num: nums) {
            total_xor ^= num;
        }

        int diff = total_xor ^ k;

        return __builtin_popcount(diff);
    }
};