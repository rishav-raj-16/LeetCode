class Solution {
public:
    int tribonacci(int n) {
        if(n < 2) return n;
        int a = 0, b = 1, c = 1, count = 2;
        while(count < n){
            int d = a+b+c; 
            a=b; 
            b=c; 
            c=d;
            count++;
        }
        return c;
    }
};