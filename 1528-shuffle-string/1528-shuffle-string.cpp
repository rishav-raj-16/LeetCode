class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        int n = indices.size();
        vector<char> arr(n);
        for(int i = 0; i < n; i++){
            arr[indices[i]] = s[i];
        }
        
        string ans = "";
        for(auto it: arr){
            ans += it;
        }
        return ans;
    }
};