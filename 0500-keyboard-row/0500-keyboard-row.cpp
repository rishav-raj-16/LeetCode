class Solution {
public:
    vector<string> findWords(vector<string>& words) {
      vector<unordered_set<char>> keyboardRows = {
        {'q','w','e','r','t','y','u','i','o','p'},
        {'a','s','d','f','g','h','j','k','l'},
        {'z','x','c','v','b','n','m'}
    };

    vector<string> result;
    for (const string& word : words) {
        unordered_set<char> wordSet(word.begin(), word.end());
        for (const unordered_set<char>& row : keyboardRows) {
            bool valid = true;
            for (char c : wordSet) {
                if (row.find(tolower(c)) == row.end()) {
                    valid = false;
                    break;
                }
            }
            if (valid) {
                result.push_back(word);
                break;
            }
        }
    }

    return result;
    }
};