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
    bool hasPathSum(TreeNode* root, int targetSum) {
        dfs(root,targetSum,sum);
        return res;
    }
    
private:
    long long sum = 0;
    bool res = false;
    
    void dfs (TreeNode* root, int t, long long& sum) {
        if(!root) {
            return;
        }
        
        sum += root->val;
        
        if(root->left == NULL && root->right == NULL){
            if(sum == t)
                res = true;
        }
        
        dfs(root->left,t,sum);
        dfs(root->right,t,sum);
        
        sum -= root->val;
    }
};