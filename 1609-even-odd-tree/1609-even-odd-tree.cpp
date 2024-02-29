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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
        int level = 0;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            int prev = (level % 2 == 0) ? INT_MIN : INT_MAX;

            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();

                // Check if root node value is valid
                if (level == 0 && ((level % 2 == 0 && node->val % 2 == 0) || (level % 2 != 0 && node->val % 2 != 0)))
                    return false;

                // Check for Even-Odd condition in values
                if ((level % 2 == 0 && (node->val % 2 == 0 || node->val <= prev)) ||
                    (level % 2 != 0 && (node->val % 2 != 0 || node->val >= prev)))
                    return false;

                prev = node->val;

                // Push children into the queue
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            level++;
        }

        return true;
    }
};