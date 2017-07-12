//Sorted array to balanced BST

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

TreeNode *solve(int low, int high, const vector <int> &A) {
    if (low > high) {
        return NULL;
    }
    int mid = low + (high - low) / 2;
    TreeNode *root = new TreeNode(A[mid]);
    root -> left = solve(low, mid - 1, A);
    root -> right = solve(mid + 1, high, A);
    return root;
}

TreeNode *Solution::sortedArrayToBST(const vector <int> &A) {
    return solve(0, (int) A.size() - 1, A);  
}
