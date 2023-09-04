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
    bool findTarget(TreeNode* root, int k) {
        queue<TreeNode*> nodes;
        auto start = root;
        nodes.push(root);
        while(!nodes.empty()) {
            auto node = nodes.front();
            nodes.pop();
            int x = k - node->val;
            if(check(start,x,node))
                return true;
            
            if(node->left)
                nodes.push(node->left);
            if(node->right)
                nodes.push(node->right);
        }
        
        return false;
    }
private:
    bool check(TreeNode* root,int k, TreeNode* node) {
        if(root == NULL) 
            return false;
        if(root->val == k && root != node)
            return true;
        else if(root->val > k)
            return check(root->left, k, node);
        else 
            return check(root->right,k, node);
        
    }
};