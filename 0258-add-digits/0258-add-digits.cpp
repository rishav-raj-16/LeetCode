class Solution {
public:
    int addDigits(int n) {
        
        int sum = 0;
        while(n > 0){
            int r = n % 10;
            sum  += r;
            n /= 10;
        }
        n = sum;
        if(n < 10)
            return n;
        else
            n = addDigits(n);
        return n;
    }
};