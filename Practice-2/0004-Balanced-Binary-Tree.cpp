/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int solve(TreeNode *root, bool &ans) {
        if (root == NULL || (! ans)) {
            return 0;
        }    
        int l = solve(root -> left, ans);
        int r = solve(root -> right, ans);
        if (abs(l - r) > 1) {
            ans = false;
        }
        return 1 + max(l, r);
    }
    
    bool isBalanced(TreeNode* root) {
        bool ans = true;
        solve(root, ans);
        return ans;
    }
};
