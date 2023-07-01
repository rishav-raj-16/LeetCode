class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int ans = INT_MIN;
        
        for(auto it : sentences){
            int temp = count(it);
            ans = max(ans,temp);
        }
        return ans;
    }
    
    int count(string s){
        int res = 0;
        for(char it: s)
            if(it == ' ')
                res++;
        return ++res;
    }
};