class Solution {
public:
    string removeDigit(string number, char digit) {
        string st = "";
        int n = number.length();

        for(int i = 0; i < number.length(); i++){
            if(number[i] == digit ){
                string temp = number.substr(0, i) + number.substr(i+1, n);
                st = max(st, temp);
            }
        }
        return st; 
    }
};