class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> ans, mx;
        int count = 0;
        for(auto it: nums){
            if(it > pivot){
                mx.push_back(it);
            }
            else if(it == pivot){
                count++;
                continue;
            }
            else{
                ans.push_back(it);   
            }
        }
        while(count != 0){
            ans.push_back(pivot);
            count--;
        }
        for(auto it: mx){
            ans.push_back(it);
        }
        return ans;
    }
};