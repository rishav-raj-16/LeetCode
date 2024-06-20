/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(!root)
            return {};
        bfs(root);
        
        return ans;
    }
private:
    vector<vector<int>> ans;
    
    void bfs(Node* root){
        queue<Node*> q;
        
        q.push(root);
        
        while(!q.empty()) {
            vector<int> temp;
            int sz = q.size();
            for(int i = 0; i < sz; i++) {
                auto node = q.front();
                q.pop();
            
                temp.push_back(node->val);
                
                for(int i = 0; i < node->children.size(); i++) {
                    q.push(node->children[i]);
                }
            }
            ans.push_back(temp);
        }
    }
};