class Solution {
public:
    bool test(vector<int>& nums, int l, int r){
        vector<int> temp;
        for(int i = l; i <= r; i++)
            temp.push_back(nums[i]);
        sort(temp.begin(),temp.end());
        int c= temp[1] - temp[0];
        for(int i = 1; i < temp.size()-1; i++){
            if(temp[i+1] - temp[i] != c)
                return false;
        }
        return true;
    }
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r){
        vector<bool> ans;
        for(int i = 0; i < l.size(); i++){
            ans.push_back(test(nums, l[i], r[i]));
        }
        return ans;
    }
};