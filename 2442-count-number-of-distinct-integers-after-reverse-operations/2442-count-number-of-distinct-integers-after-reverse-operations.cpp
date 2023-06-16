class Solution {
public:
    int countDistinctIntegers(vector<int>& nums) {
        set<int> st;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            int temp = reverse(nums[i]);
            nums.push_back(temp);
            st.insert(temp);
            st.insert(nums[i]);
        }
        return st.size();
    }
    int reverse(int n){
        int res = 0;
        while(n > 0){
            int r = n % 10;
            res = (res * 10) + r;
            n /= 10;
        }
        return res;
    }
};