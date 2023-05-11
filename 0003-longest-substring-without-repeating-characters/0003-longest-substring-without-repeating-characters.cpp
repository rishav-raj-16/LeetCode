class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s == "") return 0;
        set<char> ch;
        int mx = INT_MIN;
        
        int l = 0, r = 0;
        while(r < s.size()){
            if(ch.find(s[r]) == ch.end()){
                ch.insert(s[r]);
                mx = max(mx,r-l+1);
                r++;
            }
            else{
                ch.erase(s[l]);
                l++;
            }
        }
        return mx;
    }
};