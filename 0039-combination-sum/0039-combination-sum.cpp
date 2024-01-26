class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> curr;
        int sum = 0;
        solve(0,candidates,target,sum,curr);
        return res;
    }
    
private:
    vector<vector<int>> res;
    
    void solve(int indx, vector<int>& arr, int& t, int sum, vector<int> curr) {
        if(indx >= arr.size() || sum > t) return;
        
        sum += arr[indx];
        curr.push_back(arr[indx]);
        if(sum == t) res.push_back(curr);
        
        solve(indx,arr,t,sum,curr);
        
        curr.pop_back();
        sum -= arr[indx];
        solve(indx+1,arr,t,sum,curr);
    }
};