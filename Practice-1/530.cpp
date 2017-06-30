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
    void solve(TreeNode *root, int &min_diff, int &val) {
        if (root -> left != NULL) {
            solve(root -> left, min_diff, val);
        }
        if (val >= 0) {
            min_diff = min(min_diff, (root -> val) - val);
        }
        val = root -> val;
        if (root -> right != NULL) {
            solve(root -> right, min_diff, val);
        }
    }
    
    int getMinimumDifference(TreeNode *root) {
	int min_diff = INT_MAX;
        int val = -1;
        solve(root, min_diff, val);
        return min_diff;
    }
};
