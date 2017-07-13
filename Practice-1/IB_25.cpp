/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode *solve(vector <int> &inorder, vector <int> &postorder, int s1, int e1, int s2, int e2) {
    if (s1 > e1 || s2 > e2) {
        return NULL;
    }
    TreeNode *root = new TreeNode(postorder[e2]);
    int pos;
    for (int i = s1; i <= e1; i++) {
        if (inorder[i] == postorder[e2]) {
            pos = i;
            break;
        }
    }
    root -> left = solve(inorder, postorder, s1, pos - 1, s2, s2 + pos - 1 - s1);
    root -> right = solve(inorder, postorder, pos + 1, e1, s2 + pos - s1, e2 - 1);
    return root;
}

TreeNode *Solution::buildTree(vector<int> &inorder, vector<int> &postorder) {
    return solve(inorder, postorder, 0, (int) inorder.size() - 1, 0, (int) postorder.size() - 1);    
}
