class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> ans;
        int mx = INT_MIN;
        for(auto it: candies){
            mx = max(mx,it);
        }
        for(auto it: candies){
            it += extraCandies;
            if(it >= mx)
                ans.push_back(true);
            else
                ans.push_back(false);
            it -= extraCandies;
        }
        return ans;
    }
};