class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> ans; 
        permuteRecursive(nums,0,ans);
        
        vector<vector<int>> res(ans.begin(),ans.end());
        return res;
    }
    
private:
    void permuteRecursive(vector<int> &num, int begin, set<vector<int> > &result)	{
		if (begin >= num.size()) {
		    result.insert(num);
		    return;
		}
		
		for (int i = begin; i < num.size(); i++) {
		    swap(num[begin], num[i]);
		    permuteRecursive(num, begin + 1, result);
		    swap(num[begin], num[i]);
		}
    }
};