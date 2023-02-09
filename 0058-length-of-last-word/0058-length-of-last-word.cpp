class Solution {
public:
    int lengthOfLastWord(string s) {
        int a=0, i=s.size()-1;
        while(i>=0 && s[i]==' '){
            i--;
        }
        while(i>=0 && s[i]!=' '){
            i--; a++;
        }
        return a;
    }
};