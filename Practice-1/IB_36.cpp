/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
TreeNode *solve(vector <int> &A, int start, int end) {
    if (start > end) {
        return NULL;
    }    
    int pos = start;
    for (int i = start; i <= end; i++) {
        if (A[i] > A[pos]) {
            pos = i;
        }
    }
    TreeNode *root = new TreeNode(A[pos]);
    root -> left = solve(A, start, pos - 1);
    root -> right = solve(A, pos + 1, end);
    return root;
}

TreeNode* Solution::buildTree(vector<int> &A) {
    if (A.empty()) {
        return NULL;
    }
    return solve(A, 0, (int) A.size() - 1);
}
