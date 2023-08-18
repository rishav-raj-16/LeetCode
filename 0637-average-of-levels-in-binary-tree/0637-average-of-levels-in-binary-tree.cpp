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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        queue<TreeNode*> store;
        
        if(root == NULL) return {};
        
        store.push(root);
        
        while(!store.empty()){
            int sz = store.size();
            vector<int> temp;
            double sum = 0, count = 0;
            for(int i = 0; i < sz; i++){
                TreeNode* curr = store.front();
                store.pop();
                
                if(curr->left != NULL) store.push(curr->left);
                if(curr->right != NULL) store.push(curr->right);
                sum += double(curr->val);
                count++;
            }
            ans.push_back(sum/count);
        }
        return ans;
    }
};