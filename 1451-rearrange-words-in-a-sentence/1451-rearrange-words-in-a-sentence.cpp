class Solution {
public:
    string arrangeWords(string text) {
        vector<pair<pair<int, int>, string>> store;
        
        // Capitalize the first letter of the input
        text[0] = tolower(text[0]);

        int start = 0;
        int end = text.find(' ');
        int index = 0;
        
        while (end != string::npos) {
            string word = text.substr(start, end - start);
            store.push_back(make_pair(make_pair(word.length(), index), word));
            start = end + 1;
            end = text.find(' ', start);
            index++;
        }
        
        // Add the last word
        string word = text.substr(start);
        store.push_back(make_pair(make_pair(word.length(), index), word));

        sort(store.begin(), store.end());

        string result;
        for (const auto& p : store) {
            result += p.second;
            result += ' ';
        }
        result.pop_back(); // Remove the trailing space
        
        // Capitalize the first letter of the result
        result[0] = toupper(result[0]);

        return result;
    }
};