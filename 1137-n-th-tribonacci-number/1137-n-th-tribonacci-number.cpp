class Solution {
public:
    int tribonacci(int n) {
        vector<int> mp(38,0);
        
        mp[1] = 1;
        mp[2] = 1;
        
        for(int i = 0; i <= n; i++){
            if(i == 0 || i == 1 || i == 2) continue;
            mp[i] = mp[i-1] + mp[i-2] + mp[i-3];
        }
        return mp[n];
    }
};