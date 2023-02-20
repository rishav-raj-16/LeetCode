class Solution {
public:
    int subtractProductAndSum(int n) {
        int product=1, sum=0;
        while(n>0){
            int r = n%10;
            product *= r;
            sum += r;
            n/=10;
        } 
        int ans=product-sum;
        return ans;
    }
};