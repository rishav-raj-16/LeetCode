class Solution {
public:
    int addDigits(int n) {
        if(n < 10)
            return n;
        while(n > 0){
            n = check(n);
            if(n < 10) break;
        }
        return n;
    }
    
    int check(int n){
        int sum = 0;
        while(n > 0){
            int r = n % 10;
            sum  += r;
            n /= 10;
        }
        return sum;
    }
};