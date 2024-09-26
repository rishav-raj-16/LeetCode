class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int cnt = 0, ans = 0;
        int l = 0, r = 0;

        while(r < nums.size()) {
            if(nums[r] == 0) cnt++;

            while(cnt > k) {
                if(nums[l] == 0) cnt--;
                l++;
            }

            ans = max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};