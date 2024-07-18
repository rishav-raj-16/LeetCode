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
    int countPairs(TreeNode* root, int distance) {
        vector<vector<TreeNode*>> all_paths;
        vector<TreeNode*> curr_path;
        int cnt = 0;
        
        find_all_path(root, curr_path, all_paths);
        
        for (int i = 0; i < all_paths.size() - 1; ++i) {
            for (int j = i + 1; j < all_paths.size(); ++j) {
                vector<TreeNode*>& path1 = all_paths[i];
                vector<TreeNode*>& path2 = all_paths[j];
                int k = 0;
                while (k < path1.size() && k < path2.size() && path1[k] == path2[k]) {
                    ++k;
                }
                int dis = (path1.size() - k) + (path2.size() - k);
                if (dis <= distance) {
                    ++cnt;
                }
            }
        }
        
        return cnt;
    }
    
private:
    void find_all_path(TreeNode* root, vector<TreeNode*>& curr_path, vector<vector<TreeNode*>>& all_paths) {
        if (!root) return;
        
        curr_path.push_back(root);
        
        if (!root->left && !root->right) {
            all_paths.push_back(curr_path);
        }
        
        find_all_path(root->left, curr_path, all_paths);
        find_all_path(root->right, curr_path, all_paths);
        
        curr_path.pop_back();
    }
};