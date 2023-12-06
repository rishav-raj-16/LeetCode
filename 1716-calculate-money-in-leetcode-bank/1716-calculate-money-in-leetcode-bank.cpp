class Solution {
public:
    int totalMoney(int n) {
        int numberOfWeeks = n / 7;
        int ans = 0;
        
        for(int i = 1; i <= numberOfWeeks; i++)
            ans += 7 * (i+3);
        
        for(int i = 7 * numberOfWeeks; i < n; i++)
            ans += ++numberOfWeeks;
        
        return ans;
    }
};