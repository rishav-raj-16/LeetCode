class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size(),ans = 0;
        int l = 0, r = 0, mxCnt = 0;
        int hash[26] = {0};

        while(r < n) {
            hash[s[r]-'A']++;
            mxCnt = max(mxCnt,hash[s[r]-'A']);

            while(r-l+1 - mxCnt > k) {
                hash[s[l]-'A']--;
                for(int i = 0; i < 26; i++) mxCnt = max(mxCnt,hash[i]);
                l++;
            }

            ans = max(ans,r-l+1);
            r++;
        }

        return ans;
    }
};