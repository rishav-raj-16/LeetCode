class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0)
            return 1.0;
        if (n == 1)
            return x;
        if (n == -1)
            return 1.0 / x;
        double half_pow = myPow(x, n / 2);
        double result = half_pow * half_pow;
        if (n % 2 == 0) {
            return result;
        } else {
            return (n > 0) ? (result * x) : (result / x);
        }
    }
};