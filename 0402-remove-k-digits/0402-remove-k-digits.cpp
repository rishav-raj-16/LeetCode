class Solution {
public:
    string removeKdigits(string num, int k) {
        string result;
        for (char c : num) {
            while (k > 0 && !result.empty() && result.back() > c) {
                result.pop_back();
                k--;
            }
            result.push_back(c);
        }
        result.resize(result.size() - k);
        auto it = result.find_first_not_of('0');
        result.erase(0, it);
        return result.empty() ? "0" : result;
    }
};