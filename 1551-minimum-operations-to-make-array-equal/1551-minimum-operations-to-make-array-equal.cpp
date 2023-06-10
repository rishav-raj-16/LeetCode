class Solution {
public:
    int minOperations(int n) {
        int mid_i, mid_el, ans = 0;
        
        mid_i = n/2;
        mid_el = (2 * mid_i) + 1;
        
        for(int i = 0; i < n/2; i++){
            ans += (mid_el - ((2*i)+1));
        }
        if(n % 2 == 0){
            return ans-mid_i;
        }
        return ans;
    }
};