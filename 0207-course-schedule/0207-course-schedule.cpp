class Solution {
public:
    bool canFinish(int V, vector<vector<int>>& prerequisites) {
        vector<int> adj[V];
	    
	    for(auto it: prerequisites){
	        adj[it[0]].push_back(it[1]);
	    }
	    vector<int> indegree(V,0);
	    int cnt = 0;
	    
	    for(int i = 0; i < V; i++) {
	        for(auto it:adj[i])
	         indegree[it]++;
	    }
	    
	    queue<int> q;
	    
	    for(int i = 0; i < V; i++) {
	        if(!indegree[i]){
	            q.push(i);
	        }
	    }
	    
	    while(!q.empty()) {
	        int node = q.front();
	        q.pop();
	        cnt++;
	        
	        for(auto it:adj[node]){
	            indegree[it]--;
	            if(!indegree[it]){
	                q.push(it);
	            }
	        }
	    }
	    return cnt == V;
    }
};