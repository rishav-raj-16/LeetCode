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
    int amountOfTime(TreeNode* root, int start) {
        auto target = makeParent(root, start);
        int ans = bfs(target);
        return ans;
    }

private:
    map<TreeNode*, TreeNode*> parents;

    TreeNode* makeParent(TreeNode* root, int start) {
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* res = nullptr;

        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                auto node = q.front();
                q.pop();
                if (node->val == start) res = node;

                if (node->left) {
                    parents[node->left] = node;
                    q.push(node->left);
                }

                if (node->right) {
                    parents[node->right] = node;
                    q.push(node->right);
                }
            }
        }
        return res;
    }

    int bfs(TreeNode* target) {
        unordered_set<TreeNode*> vis;
        vis.insert(target);
        queue<TreeNode*> q;
        q.push(target);
        int time = 0;

        while (!q.empty()) {
            int sz = q.size(), fl = 0;
            for (int i = 0; i < sz; i++) {
                auto node = q.front();
                q.pop();

                if (node->left && vis.find(node->left) == vis.end()) {
                    fl = 1;
                    vis.insert(node->left);
                    q.push(node->left);
                }

                if (node->right && vis.find(node->right) == vis.end()) {
                    fl = 1;
                    vis.insert(node->right);
                    q.push(node->right);
                }

                if (parents[node] && vis.find(parents[node]) == vis.end()) {
                    fl = 1;
                    vis.insert(parents[node]);
                    q.push(parents[node]);
                }
            }
            if (fl) time++;
        }
        return time;
    }
};
