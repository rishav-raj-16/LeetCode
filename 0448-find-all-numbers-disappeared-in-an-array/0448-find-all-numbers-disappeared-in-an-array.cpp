class Solution {
public:
    bool find_el(vector<int>&arr, int a){
        int low = 0, high = arr.size() - 1;
        while(low <= high){
            int mid = (high + low) / 2;
            if(arr[mid] == a){
                return false;
            }
            else if(a < arr[mid]){
                high = mid -1;
            }
            else{
                low = mid + 1;
            }
        }
        return true;
    }
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> res; 
        for(int i = 1; i <= nums.size(); i++){
            if(find_el(nums,i))
                res.push_back(i);
        }
        return res;
    }
};