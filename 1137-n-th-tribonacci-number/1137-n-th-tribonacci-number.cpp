class Solution {
public:
    int tribonacci(int n) {
        if(n < 2) return n;
        if(n == 2) return 1;
        int a = 0, b = 1, c = 1, count = 3;
        while(count <= n){
            int d = a+b+c; 
            a=b; 
            b=c; 
            c=d;
            count++;
        }
        return c;
    }
};