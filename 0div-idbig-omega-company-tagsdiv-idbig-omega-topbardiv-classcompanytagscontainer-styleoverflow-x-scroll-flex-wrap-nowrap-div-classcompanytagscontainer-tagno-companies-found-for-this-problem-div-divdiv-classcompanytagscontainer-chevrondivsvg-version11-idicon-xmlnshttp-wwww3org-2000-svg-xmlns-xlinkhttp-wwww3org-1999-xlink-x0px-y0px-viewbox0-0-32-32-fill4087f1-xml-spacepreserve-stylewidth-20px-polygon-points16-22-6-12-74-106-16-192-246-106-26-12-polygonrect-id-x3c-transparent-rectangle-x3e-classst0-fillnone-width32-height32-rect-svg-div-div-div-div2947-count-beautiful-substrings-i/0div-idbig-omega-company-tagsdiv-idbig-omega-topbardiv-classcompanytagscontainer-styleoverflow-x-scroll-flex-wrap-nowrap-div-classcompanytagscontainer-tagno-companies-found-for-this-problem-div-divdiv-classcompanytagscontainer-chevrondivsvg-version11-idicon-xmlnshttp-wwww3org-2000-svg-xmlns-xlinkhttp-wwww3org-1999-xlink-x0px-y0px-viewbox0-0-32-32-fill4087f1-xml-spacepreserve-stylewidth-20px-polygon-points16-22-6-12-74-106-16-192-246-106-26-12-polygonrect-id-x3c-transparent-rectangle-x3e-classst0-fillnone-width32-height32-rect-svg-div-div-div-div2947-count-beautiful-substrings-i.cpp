class Solution {
public:
    int beautifulSubstrings(string s, int k) {
        unordered_set<char> st {'a','e','i','o','u'};
        int ans = 0;
        
        for(int i = 0; i < s.size(); i++) {
            int vol = 0, con = 0;
            for(int j = i; j < s.size(); j++) {
                st.find(s[j]) != st.end()? vol++ : con++;
                if(vol == con && (vol * con) % k == 0)
                    ans++;
            }
        }
        return ans;
    }
};