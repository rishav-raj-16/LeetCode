class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> visited(deadends.begin(),deadends.end());
        
        if(visited.find("0000") != visited.end()) return -1;
        
        queue<pair<string,int>> q;
        q.push({"0000", 0});
        while(!q.empty()) {
            auto temp = q.front();
            q.pop();
            
            if(temp.first == target)
                return temp.second;
            
            for(int i = 0; i < 4; i++) {
                for(auto it: {1,-1}) {
                    int newdigit = (temp.first[i] - '0' + it + 10) % 10;
                    string child = temp.first;
                    child[i] = '0' + newdigit;
                    
                    if(visited.find(child) == visited.end()){
                        visited.insert(child);
                        q.push({child, temp.second+1});
                    }
                }
            }
        }
        return -1;
    }
};