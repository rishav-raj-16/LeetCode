class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1) return {0};
        
        vector<int> ind(n, 0);
        unordered_map<int, vector<int>> map;
        for(auto& edge: edges) {
            ind[edge[0]]++;
            ind[edge[1]]++;
            map[edge[0]].push_back(edge[1]);
            map[edge[1]].push_back(edge[0]);
        }

        queue<int> queue;
        for(int i=0; i<ind.size(); i++) {
            if(ind[i] == 1) {
                queue.push(i);
            }
        }

        int processed = 0;
        while(n - processed > 2) {
            int size = queue.size();
            processed += size;
            for(int i=0; i<size; i++) {
                int poll = queue.front();
                queue.pop();
                for(int adj: map[poll]) {
                    if(--ind[adj] == 1) {
                        queue.push(adj);
                    }
                }
            }
        }

        vector<int> result;
        while(!queue.empty()) {
            result.push_back(queue.front());
            queue.pop();
        }
        return result;
    }
};
