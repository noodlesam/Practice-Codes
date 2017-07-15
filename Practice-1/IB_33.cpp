/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

void inorder(TreeNode *root, int k, int &cur, int &ans) {
    if (root == NULL || cur >= k) {
        return;
    }
    inorder(root -> left, k, cur, ans);
    if (++cur == k) {
        ans = root -> val;
    }
    inorder(root -> right, k, cur, ans);
}

int Solution::kthsmallest(TreeNode *root, int k) {
    int ans = INT_MAX;
    int cur = 0;
    inorder(root, k, cur, ans);
    return ans;
}
