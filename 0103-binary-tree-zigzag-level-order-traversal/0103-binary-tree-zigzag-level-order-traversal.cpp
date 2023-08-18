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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> store;
        int i = 1;
        
        if(root ==NULL) return {};
        
        store.push(root);
        while(!store.empty()){
            int sz = store.size();
            vector<int> temp;
            for(int i = 0; i < sz; i++){
                TreeNode* curr = store.front();
                store.pop();
                if(curr->left != NULL) store.push(curr->left);
                if(curr->right != NULL) store.push(curr->right);
                temp.push_back(curr->val);
            }
            if(i % 2 == 0) reverse(temp.begin(),temp.end());
            i++;
            ans.push_back(temp);
        }
        return ans;
    }
};