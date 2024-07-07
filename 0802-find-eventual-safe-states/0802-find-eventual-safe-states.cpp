class Solution {
public:
    // Topological Sort Solution
    vector<int> eventualSafeNodes(vector<vector<int>>& adj) {
        int V = adj.size();
        queue<int> q;
        vector<int> ans;
        vector<int> indegree(V,0);
        vector<vector<int>> nadj(V);
        
        for(int i = 0; i < V; i++) {
            for(auto it:adj[i]){
                nadj[it].push_back(i);
                indegree[i]++;
            }
        }
        for(int i = 0 ; i < V; i++) {
            if(!indegree[i])
                q.push(i);
        }
        while(!q.empty()) {
            int node = q.front();
            ans.push_back(node);
            q.pop();
            
            for(auto it:nadj[node]){
                indegree[it]--;
                if(!indegree[it]) q.push(it);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};