class Solution {
public:
    string truncateSentence(string s, int k) {
        string ans = "";
        int i = 0;
        while(i < s.length() && k > 0){
            if(s[i] == ' ') k--;
            ans += s[i++];
        }
        int m  = ans.length();
        if(ans[m-1] == ' ') ans.pop_back();
        return ans;
    }
};