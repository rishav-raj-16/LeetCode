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
    string smallestFromLeaf(TreeNode* root) {
        string smaller_str = "~";
        dfs(root,"",smaller_str);
        return smaller_str;
    }
    
private:
    void dfs(TreeNode* root, string curr_str, string &smaller_str) {
        if(!root) return;
        
        curr_str = char('a' + root->val) + curr_str;
        
        if(!root->left && !root->right) {
            smaller_str = min(curr_str,smaller_str);
        }
        
        dfs(root->left,curr_str,smaller_str);
        dfs(root->right,curr_str,smaller_str);
    }
};