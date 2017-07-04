//Max sum path in binary tree

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

int solve(TreeNode *A, int &best) {
    int ret = A -> val;
    int lft = 0;
    int rgt = 0;
    if (A -> left != NULL) {
        lft = solve(A -> left, best);
    }
    if (A -> right != NULL) {
        rgt = solve(A -> right, best);
    }
    best = max(best, ret);
    best = max(best, ret + lft + rgt);
    return ret + max(lft, rgt);
}

int Solution::maxPathSum(TreeNode* A) {
    if (A == NULL) {
        return 0;
    }
    int ans = INT_MIN;
    solve(A, ans);
    return ans;
}
