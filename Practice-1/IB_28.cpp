/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode *solve(vector <int> &preorder, vector <int> &inorder, int s1, int e1, int s2, int e2) {
    if (s1 > e1 || s2 > e2) {
        return NULL;
    }    
    TreeNode *root = new TreeNode(preorder[s1]);
    int pos;
    for (int i = s2; i <= e2; i++) {
        if (inorder[i] == preorder[s1]) {
            pos = i;
            break;
        }
    }
    root -> left = solve(preorder, inorder, s1 + 1, s1 + pos - s2, s2, pos - 1);
    root -> right = solve(preorder, inorder, s1 + pos - s2 + 1, e1, pos + 1, e2);
    return root;
}

TreeNode *Solution::buildTree(vector<int> &preorder, vector<int> &inorder) {
    return solve(preorder, inorder, 0, (int) preorder.size() - 1, 0, (int) inorder.size() - 1);
}
