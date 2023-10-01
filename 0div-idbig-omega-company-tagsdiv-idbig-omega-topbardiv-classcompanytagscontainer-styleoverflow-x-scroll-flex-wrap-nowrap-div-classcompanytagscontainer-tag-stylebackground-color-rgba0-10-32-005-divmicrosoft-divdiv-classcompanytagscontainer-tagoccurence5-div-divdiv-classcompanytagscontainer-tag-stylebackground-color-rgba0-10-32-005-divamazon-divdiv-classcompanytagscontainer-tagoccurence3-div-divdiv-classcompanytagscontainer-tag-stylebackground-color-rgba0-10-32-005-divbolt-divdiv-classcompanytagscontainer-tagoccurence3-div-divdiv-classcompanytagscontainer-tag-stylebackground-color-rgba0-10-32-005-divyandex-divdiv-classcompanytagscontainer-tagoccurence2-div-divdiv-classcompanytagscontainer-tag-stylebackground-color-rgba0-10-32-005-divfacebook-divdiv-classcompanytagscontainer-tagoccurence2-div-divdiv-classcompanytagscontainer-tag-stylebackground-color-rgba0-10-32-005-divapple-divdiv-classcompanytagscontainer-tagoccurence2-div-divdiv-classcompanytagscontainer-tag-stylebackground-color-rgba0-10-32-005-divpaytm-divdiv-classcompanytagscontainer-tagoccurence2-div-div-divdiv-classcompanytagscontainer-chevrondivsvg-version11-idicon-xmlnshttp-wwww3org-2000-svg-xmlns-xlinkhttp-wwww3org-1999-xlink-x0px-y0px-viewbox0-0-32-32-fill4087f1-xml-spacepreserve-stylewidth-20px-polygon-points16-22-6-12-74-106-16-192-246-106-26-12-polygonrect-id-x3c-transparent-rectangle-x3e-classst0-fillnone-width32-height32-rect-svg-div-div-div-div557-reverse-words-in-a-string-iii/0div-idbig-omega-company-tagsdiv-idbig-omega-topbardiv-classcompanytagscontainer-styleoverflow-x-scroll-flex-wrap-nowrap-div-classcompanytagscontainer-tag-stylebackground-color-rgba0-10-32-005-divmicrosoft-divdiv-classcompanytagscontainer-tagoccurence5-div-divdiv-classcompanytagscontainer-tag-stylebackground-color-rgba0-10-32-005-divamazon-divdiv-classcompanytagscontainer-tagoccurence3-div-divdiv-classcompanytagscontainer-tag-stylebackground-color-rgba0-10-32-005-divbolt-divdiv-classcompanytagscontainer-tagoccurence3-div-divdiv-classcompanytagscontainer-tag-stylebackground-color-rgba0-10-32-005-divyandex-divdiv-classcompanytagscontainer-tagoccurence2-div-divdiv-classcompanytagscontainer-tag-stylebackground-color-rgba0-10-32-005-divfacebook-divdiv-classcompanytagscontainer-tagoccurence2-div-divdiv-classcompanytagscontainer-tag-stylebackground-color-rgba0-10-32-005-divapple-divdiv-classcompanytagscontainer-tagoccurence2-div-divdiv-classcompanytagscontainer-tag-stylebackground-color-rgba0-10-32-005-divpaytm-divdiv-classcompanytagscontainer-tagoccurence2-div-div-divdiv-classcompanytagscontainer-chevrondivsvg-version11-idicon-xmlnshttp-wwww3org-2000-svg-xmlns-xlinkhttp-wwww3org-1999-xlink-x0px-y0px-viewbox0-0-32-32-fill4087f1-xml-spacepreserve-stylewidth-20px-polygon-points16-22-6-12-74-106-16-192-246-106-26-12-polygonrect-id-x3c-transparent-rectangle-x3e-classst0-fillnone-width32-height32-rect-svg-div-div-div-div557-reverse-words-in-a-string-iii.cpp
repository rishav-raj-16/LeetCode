class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == ' ') continue;
            else {
                string temp = "";
                int j = i;
                for(; j < s.size(); j++) {
                    if(s[j] == ' ') break;
                    
                    temp += s[j];
                }
                i = j;
                reverse(temp.begin(),temp.end());
                ans += temp + ' ';
            }
        }
        
     
            ans.pop_back();
        

        return ans;
    }
};