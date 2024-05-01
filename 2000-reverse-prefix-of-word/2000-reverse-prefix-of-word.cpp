class Solution {
public:
    string reversePrefix(string word, char ch) {
        int i; bool temp = false;
        for(i = 0; i < word.size(); i++) {
            if(word[i] == ch){
                temp = true;
                break;
            }
        }
        
        if(temp) reverse(word.begin(),word.begin()+i+1);
        return word;
    }
};