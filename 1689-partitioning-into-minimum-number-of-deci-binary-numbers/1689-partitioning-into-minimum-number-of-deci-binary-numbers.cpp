class Solution {
public:
    int minPartitions(string s) {
        int n = s.length(), ans = s[0] - '0';
        
        if(n == 1) return s[0] - '0';
        
        for(int i = 1; i < n; i++)
            ans = max(ans,s[i] - '0');
        return ans;
    }
};