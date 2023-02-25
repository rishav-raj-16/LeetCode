class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size(),j,k;
        set<vector<int>> s;
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        for(int i=0; i<n-2; i++){
            if(i>0 && nums[i]==nums[i-1])
            continue;
            j=i+1;
            k=n-1;
            while(j<k){
                int sum = nums[i]+nums[j]+nums[k];
                if(sum == 0){
                    s.insert({nums[i],nums[j],nums[k]});
                    j++;
                    k--;
                }
                else if( sum > 0){
                    k--;
                }
                else
                    j++;
            }
        }
        for(auto t:s)
           res.push_back(t);
        return res;
    }
};