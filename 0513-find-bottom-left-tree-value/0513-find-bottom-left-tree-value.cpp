/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        bfs(root);
        return ans;
    }

private:
    
    int ans = 0;
    
    void bfs(TreeNode* root) {
        queue<TreeNode*> q;
        
        q.push(root);
        
        while(!q.empty()) {
            int sz = q.size();
            for(int i = 0; i < sz; i++) {
                auto node = q.front();
                q.pop();
                
                if(i == 0)
                    ans = node->val;
                
                if(node->left)
                    q.push(node->left);
                
                if(node->right)
                    q.push(node->right);
            }
        }
    }
    
};