class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> ch;
        
        for(int i = 0; i < s.length(); i++){
            if(ch.empty())
             ch.push(s[i]);

            else if(ch.top() == s[i]){
                ch.pop();
            }
            else
            ch.push(s[i]);
        }
        string str = "";
        int n = ch.size();
        while(!ch.empty()){
            str += ch.top();
            ch.pop();
        }
        reverse(str.begin(),str.end());
        return str;
    }
};