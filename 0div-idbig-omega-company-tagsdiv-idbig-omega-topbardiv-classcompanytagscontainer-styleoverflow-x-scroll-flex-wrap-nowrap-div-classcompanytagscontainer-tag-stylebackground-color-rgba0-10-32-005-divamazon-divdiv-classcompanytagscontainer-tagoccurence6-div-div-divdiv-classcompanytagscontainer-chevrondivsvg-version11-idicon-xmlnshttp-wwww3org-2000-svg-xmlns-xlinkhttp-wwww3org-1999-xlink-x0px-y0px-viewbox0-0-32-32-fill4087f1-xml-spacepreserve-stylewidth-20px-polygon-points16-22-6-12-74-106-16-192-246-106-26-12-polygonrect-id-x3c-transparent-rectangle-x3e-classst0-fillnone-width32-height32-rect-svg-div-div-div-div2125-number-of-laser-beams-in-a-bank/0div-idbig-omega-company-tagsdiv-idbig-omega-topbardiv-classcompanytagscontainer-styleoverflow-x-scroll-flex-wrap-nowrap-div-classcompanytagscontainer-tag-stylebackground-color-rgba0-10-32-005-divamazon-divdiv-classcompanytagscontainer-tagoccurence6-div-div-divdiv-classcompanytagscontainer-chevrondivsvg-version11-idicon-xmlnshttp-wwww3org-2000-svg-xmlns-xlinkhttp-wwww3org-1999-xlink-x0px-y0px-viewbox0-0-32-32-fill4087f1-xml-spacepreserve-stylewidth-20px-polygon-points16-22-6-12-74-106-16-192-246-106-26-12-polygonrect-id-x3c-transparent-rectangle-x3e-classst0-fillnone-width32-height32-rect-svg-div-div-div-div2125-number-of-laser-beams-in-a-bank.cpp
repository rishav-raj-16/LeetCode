class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int r1 = 0, r2 = 0, ans = 0;
        
        for(int i = 0; i < bank.size(); i++){
            r2 = 0;
            for(int j = 0; j < bank[0].size(); j++){
                if(bank[i][j] == '1') r2++;
            }
            if(r2 == 0) continue;
            ans += r1 * r2;
            r1 = r2;
        }
        return ans;
    }
};