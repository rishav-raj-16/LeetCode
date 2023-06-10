class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int laser = 0, ans = 0;
        vector<int> count;
        
        for(int i = 0; i < bank.size(); i++){
            for(int j = 0; j < bank[0].size(); j++){
                if(bank[i][j] == '1') laser++;
            }
            if(laser > 0) count.push_back(laser);
            laser = 0;
        }
        if(count.size() == 1 || count.size() == 0) return ans;
        
        for(int i = 0; i < count.size()-1; i++)
            ans += (count[i] * count[i+1]);
        return ans;
    }
};