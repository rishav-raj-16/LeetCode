class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.length();
        if(n==0)
        return true;

        string a;
        for(int i =0; i<n; i++){
            if(s[i] >= 'A' && s[i] <= 'Z'){
                s[i] = tolower(s[i]);
                a+=s[i];
            }
            else if(s[i] >='a' && s[i] <= 'z' ){
                a+=s[i];
            }
            else if(s[i] >= '0' && s[i] <= '9'){
                a+=s[i];
            }
            else 
            continue;
        }
        s=a;
        reverse(a.begin(),a.end());
        if(s==a)
        return true;
        return false;
    }
};