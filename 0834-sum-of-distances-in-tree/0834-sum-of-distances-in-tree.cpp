class Solution {
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;
        N = n;
        count.resize(n, 0);

        for(auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        result_base_node = 0;
        dfs(adj, 0, -1, 0);

        vector<int> result(n, 0);
        result[0] = result_base_node;
        DFS(adj, 0, -1, result);

        return result;
    }

private:
    long result_base_node = 0;
    vector<int> count;
    int N;
    
    int dfs(unordered_map<int, vector<int>>& adj, int curr_node, int prev_node, int curr_depth) {
        int total_node = 1;
        result_base_node += curr_depth;

        for(int &child : adj[curr_node]) {
            if(child != prev_node)
                total_node += dfs(adj, child, curr_node, curr_depth + 1);
        }

        count[curr_node] = total_node;
        return total_node;
    }
    
    void DFS(unordered_map<int, vector<int>>& adj, int parent_node, int prev_node, vector<int>& result) {
        for(int &child : adj[parent_node]) {
            if(child != prev_node) {
                result[child] = result[parent_node] - count[child] + (N - count[child]);
                DFS(adj, child, parent_node, result);
            }
        }
    }
};
