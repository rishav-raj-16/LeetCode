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
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        dfs(root,ans);
        return ans;
    }
    
    int dfs(TreeNode* root, int& mx) {
        if(!root) {
            return 0;
        }
        
        int lh = max(0,dfs(root->left,mx));
        int rh = max(0,dfs(root->right,mx));
        
        mx = max(mx,root->val + lh + rh);
        
        return root->val + max(lh,rh);
    }
};