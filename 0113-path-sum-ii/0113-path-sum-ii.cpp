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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        dfs(root,targetSum,sum,curr);
        return res;
    }
    
private:
    long long sum = 0;
    vector<vector<int>> res;
    vector<int> curr;
    
    void dfs (TreeNode* root, int t, long long& sum, vector<int>& curr) {
        if(!root) {
            return;
        }
        
        sum += root->val;
        curr.push_back(root->val);
        
        if(root->left == NULL && root->right == NULL){
            if(sum == t)
                res.push_back(curr);
        }
        
        dfs(root->left,t,sum,curr);
        dfs(root->right,t,sum,curr);
        
        sum -= root->val;
        curr.pop_back();
    }
};