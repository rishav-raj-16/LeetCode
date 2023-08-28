class Solution {
public:
    bool reorderedPowerOf2(int n) {
        map<int,int> number;
        
        while(n > 0) {
            number[n % 10]++;
            n /= 10;
        }
        
        for(int i = 0; i <= 30; i++) {    
            int candidate = pow(2,i);
            map<int,int> can_mp;
            
            while(candidate) {
                can_mp[candidate % 10]++;
                candidate /= 10;
            }
            
            if(can_mp == number)
                return true;
        }
        return false;
    }
};