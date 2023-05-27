class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        set<int> s;
        for(int i = 1; i <= bound; i*=x){
            for(int j = 1; j+i <= bound; j *= y){
                int sum = i + j;
                s.insert(sum);
                if(y == 1) break;
            }
            if(x == 1) break;
        }
        vector<int> ans(s.begin(),s.end());
        return ans; 
    }
};