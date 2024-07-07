class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n,0);
        vector<int> path(n,0);
        vector<int> ans;
        
        for(int i = 0 ; i < n; i++) {
            if(!vis[i])
                dfs(i,graph,vis,path);
        }
        
        for(int i = 0; i < n; i++) {
            if(!path[i])
                ans.push_back(i);
        }
        return ans;
    }
    
private:
    bool dfs(int &node, vector<vector<int>>& graph, vector<int>& vis, vector<int>& path) {
        vis[node] = 1;
        path[node] = 1;
        
        for(int it:graph[node]) {
            if(!vis[it]) {
                if(dfs(it,graph,vis,path))
                    return true;
            } else if(path[it])
                return true;
        }
        
        path[node] = 0;
        return false;
    }
};