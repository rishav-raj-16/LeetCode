class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        set<vector<int>> s;
        int n = nums.size();
        
        sort(nums.begin(),nums.end());
        for(int i = 0; i < n-3; i++){
            if(i > 0 && nums[i] == nums[i-1])
                continue;
            for(int j = i+1; j <n-2; j++){
                if(j > i+1 && nums[j] == nums[j-1])
                    continue;
                int k = j+1;
                int l = n-1;
                while(k < l){
                    long long sum = nums[i]+nums[j];
                    sum += nums[k];
                    sum += nums[l];
                    if(sum < target){
                        k++;
                    }
                    else if(sum > target){
                        l--;
                    }
                    else{
                        vector<int> temp = {nums[i],nums[j],nums[k],nums[l]};
                        s.insert(temp);
                        k++;
                        l--;
                    }
                }
            }
        }
        for(auto it: s)
            ans.push_back(it);
        return ans;
    }
};