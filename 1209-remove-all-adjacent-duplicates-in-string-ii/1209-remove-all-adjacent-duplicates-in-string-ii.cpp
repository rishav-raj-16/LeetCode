class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>> st;
        st.push({'A',1});
        for(auto i:s){
            i==st.top().first?st.push({i,st.top().second+1}):st.push({i,1});
            if(st.top().second==k){
                int temp=k;
                while(temp--)st.pop();
            }
        }
        string str;
        while(st.top().first!='A'){
            str.push_back(st.top().first);
            st.pop();
        }
        reverse(str.begin(),str.end());
        return str;
    }
};