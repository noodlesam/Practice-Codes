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
    int minDepth(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        int l = minDepth(root -> left);
        int r = minDepth(root -> right);
        if (l && !r) {
            return 1 + l;
        }
        if (!l && r) {
            return 1 + r;
        }
        return 1 + min(l, r);
    }
};
