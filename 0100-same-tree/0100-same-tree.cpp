class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        queue<TreeNode*> q1, q2;
        
        q1.push(p);
        q2.push(q);
        
        while(!q1.empty() && !q2.empty()) {
            TreeNode* c1 = q1.front();
            TreeNode* c2 = q2.front();
            q1.pop();
            q2.pop();
            
            if (c1 == nullptr && c2 == nullptr) {
                continue; // Both nodes are nullptr, so they are equal at this point.
            }
            if (c1 == nullptr || c2 == nullptr) {
                return false; // One node is nullptr while the other is not.
            }
            if (c1->val != c2->val) {
                return false; // Node values are different.
            }
            
            q1.push(c1->left);
            q1.push(c1->right);
            q2.push(c2->left);
            q2.push(c2->right);
        }
        
        return q1.empty() && q2.empty(); // Both queues should be empty if trees are identical.
    }
};
