class Solution {
public:
    int minimizedStringLength(string s) {
        vector<int> st(26,0);
        int ans = 0;
        for(auto it: s){
            st[it - 'a'] = 1;
        }
        for(auto it : st){
            if(it == 1)
                ans++;
        }
        return ans;
    }
};