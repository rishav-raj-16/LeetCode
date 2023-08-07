class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> start;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '(')
                start.push(i);
            else if(s[i] == ')'){
                int st = start.top();
                reverse(s.begin()+st, s.begin()+i);
                start.pop();
            }
        }
        
        string ans = "";
        for(auto it: s){
            if(it =='(' || it == ')') continue;
            ans += it;
        }
        return ans;
    }
};