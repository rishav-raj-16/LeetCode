class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> p, n;
        
        for(int it:nums){
            if(it > 0) p.push_back(it);
            else
                n.push_back(it);
        }
        
        nums = {};
        
        for(int i = 0; i<p.size(); i++){
            nums.push_back(p[i]);
            nums.push_back(n[i]);
        }
        return nums;
    }
};