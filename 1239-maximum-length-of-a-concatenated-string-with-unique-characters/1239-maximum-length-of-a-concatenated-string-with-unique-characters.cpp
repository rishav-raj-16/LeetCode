class Solution {
public:
    int maxLength(vector<string>& arr) {
        unordered_set<char> uniqueChar;
        return maxLengthHelper(arr, 0, uniqueChar);
    }
    
private:
    int maxLengthHelper(vector<string>& arr, int indx, unordered_set<char>& uniqueChar) {
        if(indx == arr.size()){
            return uniqueChar.size();
        }
     
        unordered_set<char> includedChar = uniqueChar;
        bool isIncluded = true;
        for(auto ch: arr[indx]) {
            if(includedChar.find(ch) != includedChar.end()) {
                isIncluded = false;
                break;
            }
            includedChar.insert(ch);
        }
        
        int lengthIfIncluded = 0;
        if(isIncluded) {
            lengthIfIncluded = maxLengthHelper(arr, indx+1, includedChar);
        }
        
        int lengthIfExcluded = maxLengthHelper(arr, indx+1, uniqueChar);
        
        return max(lengthIfIncluded, lengthIfExcluded);
    }
};