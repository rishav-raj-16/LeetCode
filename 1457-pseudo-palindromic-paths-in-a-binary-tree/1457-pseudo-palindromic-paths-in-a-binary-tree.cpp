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
    int pseudoPalindromicPaths (TreeNode* root) {
        unordered_map<int,int> mp;
        preorder(root,mp);
        
        return cnt;
    }
    
private:
    int cnt = 0;
    
    void preorder(TreeNode* root, unordered_map<int,int> mp) {
        if (root == NULL) 
            return;
        
        mp[root->val]++;
        
        if (root->left == NULL && root->right == NULL) {
            int oddcnt = 0;
            for(auto it : mp){
                if(it.second%2 == 1)
                    oddcnt++;
            }
            if(oddcnt <= 1) cnt++;
            return;
        }
        
        preorder(root->left, mp);
        preorder(root->right, mp);
    }
};