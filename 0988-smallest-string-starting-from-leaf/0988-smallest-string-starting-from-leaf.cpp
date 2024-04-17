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
        string s = "";
        dfs(root,s);
        return ans;
    }
private:
    string ans = "";
    void dfs(TreeNode* root, string s) {
        if(!root) return;
        
        char c = 'a'+ root->val;
        s = c + s;
        if(!root->left && !root->right) {
            if(ans == "")
                ans = s;
            else {
                if(ans > s)
                    ans = s;
            }
        }
        dfs(root->left, s);
        dfs(root->right, s);
    } 
};