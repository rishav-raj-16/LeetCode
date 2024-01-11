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
    int maxAncestorDiff(TreeNode* root) {
        maxdif = -1;
        AllMaxDiff(root);
        return maxdif;
    }

private:
    int maxdif;
    
    void AllMaxDiff(TreeNode* root) {
        if(root == NULL) return;
        
        OneMaxDiff(root,root->left);
        OneMaxDiff(root,root->right);
        
        AllMaxDiff(root->left);
        AllMaxDiff(root->right);
    }
    
    void OneMaxDiff(TreeNode* root, TreeNode* child) {
        if(root == NULL || child == NULL) return;
        
        maxdif = max(maxdif, abs(root->val-child->val));
        
        OneMaxDiff(root,child->left);
        OneMaxDiff(root,child->right);
    }
};