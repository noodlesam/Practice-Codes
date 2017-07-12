//Lowest common ancestor of a binary tree

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
    int dfs(TreeNode *root, TreeNode *p, TreeNode *q, TreeNode *&ans) {
        int ret = 0;
        if (root == p || root == q) {
            ret++;
        }
        if (root -> left != NULL) {
            ret += dfs(root -> left, p, q, ans);
        }
        if (root -> right != NULL) {
            ret += dfs(root -> right, p, q, ans);
        }
        if (ret == 2 && ans == NULL) {
            ans = root;
        }
        return ret;
    }
    
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode *ans = NULL;
        if (root != NULL) {
            dfs(root, p, q, ans);
        }
        return ans;
    }
};
