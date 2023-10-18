class Solution {
    public int reverse(int x) {
        long ans = 0;
        int s = 1;
        if(x < 0){
            s = -1;
            x *= -1;
        }
        
        while(x > 0) {
            int dig = x % 10;
            ans = (ans * 10) + dig;
            x /= 10;
        }
        
        if(ans > Integer.MAX_VALUE || ans < Integer.MIN_VALUE)
            return 0;
        
        return (int) ans * s;
    }
}