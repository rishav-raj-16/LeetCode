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
    int widthOfBinaryTree(TreeNode* root) {
        if (!root)
            return 0;
        queue<pair<TreeNode*, long long>> q;
        int ans = 0;
        q.push({root, 0});
        while (!q.empty()) {
            int sz = q.size();
            long long mn = q.front().second;
            long long first, last;

            for (int i = 0; i < sz; i++) {
                long long id = q.front().second - mn;
                auto node = q.front().first;
                q.pop();
                if (i == 0) first = id;
                if (i == sz - 1) last = id;
                if (node->left) 
                    q.push({node->left, id * 2 + 1});
                if (node->right) 
                    q.push({node->right, id * 2 + 2});
            }
            ans = max(ans, static_cast<int>(last - first + 1));
        }
        return ans;
    }
};