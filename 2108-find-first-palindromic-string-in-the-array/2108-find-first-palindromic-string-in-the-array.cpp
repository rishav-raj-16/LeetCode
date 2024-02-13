class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        string ans = "";
        
        for(auto it:words) {
            if(isPalindrom(it)){
                ans = it;
                break;
            }
        }
        return ans;
    }
    
private:
    
    bool isPalindrom(string& s){
        int n = s.size();
        bool res = true;
        for(int i = 0; i < n/2; i++) {
            if(s[i] != s[n-i-1])
                res = false;
        }
        return res;
    }
};