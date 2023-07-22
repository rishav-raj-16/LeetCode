class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string, int> domainCountMap;
        
        for (const string& cpdomain : cpdomains) {
        istringstream iss(cpdomain);
        int count;
        string domain;
        iss >> count >> domain;

        // Update the count for the current domain and its parent domains
        while (true) {
            domainCountMap[domain] += count;
            size_t dotPos = domain.find('.');
            if (dotPos == string::npos) break;
            domain = domain.substr(dotPos + 1);
        }
    }

    vector<string> result;
    for (const auto& entry : domainCountMap) {
        result.push_back(to_string(entry.second) + " " + entry.first);
    }

    return result;
    }
};