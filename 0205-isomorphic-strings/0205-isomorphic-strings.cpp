class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map <char , char> mp1;
        unordered_map <char , char> mp2;

        if(s.length() != t.length())
        return false;

        for(int i = 0; i<s.length(); i++)
        {
            if((mp1[s[i]] && mp1[s[i]] != t[i]) 
            || (mp2[t[i]] && mp2[t[i]] != s[i]))
            return false;
            else
            mp1[s[i]] = t[i];
            mp2[t[i]] = s[i];
        }
        return true;
    }
};