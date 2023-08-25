class Solution {
public:
    std::string convert(std::string s, int numRows) {
        if (numRows == 1 || numRows >= s.length()) {
            return s;
        }

        vector<string> rows(numRows, "");
        int index = 0;
        int step = 1;

        for (char c : s) {
            rows[index] += c;

            if (index == numRows - 1) {
                step = -1;
            } else if (index == 0) {
                step = 1;
            }

            index += step;
        }

        string result;
        for (const string& row : rows) {
            result += row;
        }

        return result;
    }
};