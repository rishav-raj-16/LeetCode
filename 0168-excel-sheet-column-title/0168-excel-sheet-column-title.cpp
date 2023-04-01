class Solution {
public:
    string convertToTitle(int columnNumber) {
        string result = "";
        while (columnNumber > 0) {
            int remainder = columnNumber % 26;
            if (remainder == 0) {
                remainder = 26;
            }
            result = char(remainder + 64) + result;
            columnNumber = (columnNumber - remainder) / 26;
        }
        return result;
    }
};