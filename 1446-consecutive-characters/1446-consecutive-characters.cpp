class Solution {
public:
    int maxPower(string s) {
        int n= s.size();
        int count =1 , ans=0, i=0;
        while(i<n){
                while(s[i]==s[i+1]){
                    i++;
                    ++count;
                }
            i++;
            ans = max(ans,count);
            count= 1;
        }
        return ans;
    }
};