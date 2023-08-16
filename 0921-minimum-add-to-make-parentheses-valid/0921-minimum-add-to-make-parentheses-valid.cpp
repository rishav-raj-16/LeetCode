class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> store;
        int ans = 0;
        
        for(auto it:s){
            if(it == '(')
                store.push(it);
            else{
                if(!store.empty() && store.top() == '(')
                    store.pop();
                else
                    ans++;
            }
        }
        return store.size()+ans;
    }
};
