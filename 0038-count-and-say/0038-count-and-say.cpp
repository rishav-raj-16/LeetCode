class Solution {
public:
    string countAndSay(int n) {
        
        string curr = "1"; //will store latest string after ith iteration
        
        if(n == 1) return curr;
        

        for(int nn = 2; nn <= n; nn++){
            
            string store = ""; // will store current iteration answer
            
            int i = 0, len = curr.length();
            while(i < len){
                char ch = curr[i];
                int j = i + 1;
                while(j < len && curr[j] == ch) j++;
                
                int times = j - i; //frequency of current(ch) consecutive same character
                store += (times + '0'); 
                store += ch;
                
                i = j;
            }
            
            curr = store;// will save current iteration answer to curr 
        }
        
        return curr;
     }
};