//Kth smallest element in BST

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
    int solve(TreeNode *root, int &k) {
        if (root != NULL) {
            int get = solve(root -> left, k);
            if (! k) {
                return get;
            } else if ((--k) == 0) {
                return root -> val;
            } else {
                return solve(root -> right, k);
            }
        }
        return 0;
    }
    
    int kthSmallest(TreeNode* root, int k) {
          return solve(root, k);
    }
};
