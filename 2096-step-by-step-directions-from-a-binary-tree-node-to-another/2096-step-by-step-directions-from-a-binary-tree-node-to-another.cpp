class Solution {
public:
    string getDirections(TreeNode* root, int startValue, int destValue) {
        auto lca = lowestCommonAncestor(root,startValue,destValue);

        string ans = "",temp = "";
        LCA_start(lca,startValue,temp,ans);
        LCA_dest(lca,destValue,temp,ans);
        return ans;
    }
    
private:
    TreeNode* lowestCommonAncestor(TreeNode* root, int& s, int& d) {
        if(!root || root->val == s || root->val == d)
            return root;

        auto left = lowestCommonAncestor(root->left,s,d);
        auto right = lowestCommonAncestor(root->right,s,d);

        if(!left) return right;
        else if(!right) return left;
        else return root;
    }

    void LCA_start(TreeNode* root, int& s, string& temp, string& ans) {
        if(!root) return;
        if(root->val == s) {
            ans += temp;
            return;
        }

        temp += 'U';

        LCA_start(root->left,s,temp,ans);
        LCA_start(root->right,s,temp,ans);

        temp.pop_back();
    }

    void LCA_dest(TreeNode* root, int& d, string& temp, string& ans) {
        if(!root) return;

        if(root->val == d){
            ans+= temp;
            return;
        }

        temp += 'R';
        LCA_dest(root->right,d,temp,ans);
        temp.pop_back();
        temp += 'L';
        LCA_dest(root->left,d,temp,ans);
        temp.pop_back();
    }
};