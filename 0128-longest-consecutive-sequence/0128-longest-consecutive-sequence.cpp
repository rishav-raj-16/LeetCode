class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty())
            return 0;
        
        int ans = INT_MIN;
        unordered_set<int> st(nums.begin(),nums.end());
        
        for(auto it:nums){
            if(st.find(it-1) == st.end()){
                int temp = it, count = 1;
                
                while(st.find(temp+1) != st.end()){
                    count++, temp++;
                }
                
                ans = max(ans,count);
            }
        }
        return ans;
    }
};