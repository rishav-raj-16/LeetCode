class Solution {
public:
    int minLengthAfterRemovals(vector<int>&v) {
        int n=v.size(),ans=n;
        for(int i=0,j=n/2; i<n/2&&j<v.size(); j++) {
            if(v[i]<v[j]) {
                i++; ans-=2;
            }
        }
        return ans;
    }
};