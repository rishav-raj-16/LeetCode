class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int sum = 0;
        int ans = INT_MIN;
        
        for(int i = 0; i<gain.size(); i++){
            sum = sum + gain[i];
            ans = max(ans,sum);
        }
        if(ans<0)
            return 0;
        return ans;
    }
};