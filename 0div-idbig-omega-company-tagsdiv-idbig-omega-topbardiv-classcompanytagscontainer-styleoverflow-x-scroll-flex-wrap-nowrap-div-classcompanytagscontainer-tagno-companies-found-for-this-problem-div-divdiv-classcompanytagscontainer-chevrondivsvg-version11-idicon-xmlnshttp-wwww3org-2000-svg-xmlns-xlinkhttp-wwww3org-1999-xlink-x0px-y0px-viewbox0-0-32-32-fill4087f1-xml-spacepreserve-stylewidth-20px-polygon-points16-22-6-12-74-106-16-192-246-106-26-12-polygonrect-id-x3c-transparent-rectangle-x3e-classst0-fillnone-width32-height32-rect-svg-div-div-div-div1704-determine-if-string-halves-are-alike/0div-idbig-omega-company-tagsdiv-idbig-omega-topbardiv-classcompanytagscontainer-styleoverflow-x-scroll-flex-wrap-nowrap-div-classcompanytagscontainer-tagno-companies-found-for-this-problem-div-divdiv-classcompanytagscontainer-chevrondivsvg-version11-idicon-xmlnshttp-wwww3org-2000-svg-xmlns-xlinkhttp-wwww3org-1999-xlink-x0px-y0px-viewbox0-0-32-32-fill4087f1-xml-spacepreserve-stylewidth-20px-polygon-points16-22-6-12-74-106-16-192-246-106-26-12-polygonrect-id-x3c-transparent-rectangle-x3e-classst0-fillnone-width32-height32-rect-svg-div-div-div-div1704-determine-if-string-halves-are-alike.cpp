class Solution {
public:
    bool halvesAreAlike(string s) {
        int n = s.size(), mid = n/2;
        int a = 0, b = 0;
        set<char> st = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        
        for(int i = 0; i < mid; i++) {
            if(st.find(s[i]) != st.end())
                a++;
        }
        
        for(int i= mid; i < n; i++) {
            if(st.find(s[i]) != st.end())
                b++;
        }
        return a == b;
    }
};