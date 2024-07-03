class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int v = isConnected.size();
        vector<int> adj[v];
        
        for(int i = 0; i < v; i++) {
            for(int j = 0; j < v; j++) {
                if(isConnected[i][j] && i != j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        
        int ans = 0;
        vector<int> vis(v,0);
        
        
        for(int i = 0; i < v; i++) {
            if(!vis[i]) {
                ans++;
                dfs(i,vis,adj);
            }
        }
        return ans;
    }
    
private:
    void dfs(int node, vector<int>& vis, vector<int> adj[]){
        vis[node] = 1;
        
        for(auto it:adj[node]) {
            if(!vis[it]) {
                dfs(it,vis,adj);
            }
        }
    }
};