class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)
        return false;
        
        int a=x;
        long int temp=0;

        while(a>0){
            int r = a%10;
            temp = (temp*10)+r;
            a=a/10;
        }
        if(x==temp)
        return true;
        return false;
    }
};