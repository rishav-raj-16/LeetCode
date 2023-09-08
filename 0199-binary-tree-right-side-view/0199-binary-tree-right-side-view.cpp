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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(root == NULL) return ans;
        
        queue<TreeNode*> store;
        store.push(root);
        while(!store.empty()) {
            int a, sz = store.size();
            for(int i = 0; i < sz; i++) {
                auto node = store.front();
                store.pop();
                a = node->val;
                
                if(node->left) store.push(node->left);
                if(node->right) store.push(node->right);
            }
            ans.push_back(a);
        }
        return ans;
    }
};