class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }
        
        int sign = (dividend < 0) ^ (divisor < 0) ? -1:1;
        
        long long ldividend = abs(static_cast<long long>(dividend));
        long long ldivisor = abs(static_cast<long long>(divisor));
        long long quotient = 0;
        
        while(ldividend >= ldivisor) {
            long long temp = ldivisor;
            long long mul = 1;
            
            while(ldividend >= temp << 1) {
                temp <<= 1;
                mul <<= 1;
            }
            
            ldividend -= temp;
            quotient += mul;
        }
        
        return sign * quotient;
    }
};