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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> t1, t2;
        dfs(root1, t1);
        dfs(root2, t2);
        
        return t1 == t2;
    }
    
    void dfs(TreeNode* root, vector<int>& t) {
        if(root == NULL)
            return;
        
        if(root->left == NULL && root->right == NULL)
            t.push_back(root->val);
        
        dfs(root->left, t);
        
        dfs(root->right, t);
    }
};