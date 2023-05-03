class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        vector<vector<int>> answer;
        set<int> v1;
        set<int> v2;
        
        for(auto it: nums1){
            if(check(it,nums2)){
                v1.insert(it);
            }
        }
        vector<int> a(v1.begin(),v1.end());
        answer.push_back(a);
        
        for(auto it: nums2){
            if(check(it,nums1)){
                v2.insert(it);
            }
        }
        vector<int> b(v2.begin(),v2.end());
        answer.push_back(b);
        return answer;
    }
    bool check(int x, vector<int> nums){
        int low = 0, high = nums.size()-1;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(nums[mid] == x){
                return false;
            }
            else if(nums[mid] < x){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return true;
    }
};