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
    int rangeSumBST(TreeNode* root, int low, int high) {
        int ans = 0;
        dfs(root, low, high, ans);
        return ans;
    }
    
    void dfs(TreeNode* root, int low, int high, int& ans) {
        if(root == NULL)
            return;
        
        if(root->val >= low && root->val <= high){
            ans += root->val;
        }
        
        if(root->left != NULL)
            dfs(root->left, low, high, ans);
        
        if(root->right != NULL)
            dfs(root->right, low, high, ans);
    }
};