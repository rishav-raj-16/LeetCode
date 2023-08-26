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
    int maxDepth(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }
        
        int count = 0;
        queue<TreeNode*> store;
        store.push(root);
        while(!store.empty()) {
            int sz = store.size();
            count++;
            for(int i = 0; i < sz; i++) {
                auto cur = store.front();
                store.pop();
                
                if(cur->left != NULL) {
                    store.push(cur->left);
                }
                if(cur->right != NULL) {
                    store.push(cur->right);
                }
            }
        }
        return count;
    }
};