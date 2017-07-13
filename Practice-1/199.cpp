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
    void dfs(TreeNode *root, int level, unordered_map <int, int> &m) {
        if (root != NULL) {
            m[level] = root -> val;
            dfs(root -> left, level + 1, m);
            dfs(root -> right, level + 1, m);
        }
    }
    vector<int> rightSideView(TreeNode* root) {
        unordered_map <int, int> m;
        vector <int> ans;
        int start = 0;
        dfs(root, 0, m);
        while (m.count(start) > 0) {
            ans.push_back(m[start]);
            start++;
        }
        return ans;
    }
};
