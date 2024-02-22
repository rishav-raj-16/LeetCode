class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        map<int,int> incoming, outgoing;
        
        for(int i = 1; i <= n; i++) {
            incoming[i] = 0, outgoing[i] = 0;
        }
        
        for(auto it:trust){
            incoming[it[1]]++;
            outgoing[it[0]]++;
        }
        
        for(int i = 1; i <= n; i++) {
            if(incoming[i] == n-1 && outgoing[i] == 0)
                return i;
        }
        return -1;
    }
};