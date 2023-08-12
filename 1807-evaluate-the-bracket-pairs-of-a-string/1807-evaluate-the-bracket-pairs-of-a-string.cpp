class Solution {
public:
    string evaluate(string& s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> knowledgeMap;
        
        for (const auto& entry : knowledge) {
            knowledgeMap[entry[0]] = entry[1];
        }
        
        string result;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                int j = i + 1;
                while (j < s.size() && s[j] != ')') {
                    j++;
                }
                string key = s.substr(i + 1, j - i - 1);
                auto it = knowledgeMap.find(key);
                
                if (it != knowledgeMap.end()) {
                    result += it->second;
                } else {
                    result += '?';
                }
                
                i = j;
            } else {
                result += s[i];
            }
        }
        
        return result;
    }
};