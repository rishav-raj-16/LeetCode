class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        int  n = strs.size();
        if(n == 0) return "";
        string ans, a = strs[0], b = strs[n-1];
        
        for(int i = 0; i < a.size(); i++) {
            if(a[i] == b[i]) {
                ans += a[i];
            }
            else{
                break;
            }
        } 
        return ans;
    }
};