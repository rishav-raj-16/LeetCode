class Solution {
public:
    bool isStrictlyPalindromic(int n) {
        for(int i = 2; i <= n-2; i++){
            string base = "";
            int temp = n;
            while(temp){
                base = to_string(temp%i) + base;
                temp /= i;
            }
            
            int n = base.size();
            
            for(int j = 0; j < n; j++){
                if(base[j] != base[n-j-1])
                    return false;
            }
        }
        return true;
    }
};