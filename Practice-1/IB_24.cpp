/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<vector<int> > Solution::zigzagLevelOrder(TreeNode* A) {
    vector <vector <int> > ans;
    if (A == NULL) {
        return ans;
    }
    queue <pair <TreeNode *, int> > q;
    q.push({A, 0});
    while (! q.empty()) {
        auto x = q.front();
        q.pop();
        int level = x.second;
        if (ans.size() < level + 1) {
            vector <int> empty;
            ans.push_back(empty);
        }
        ans[level].push_back(x.first -> val);
        if (x.first -> left) {
            q.push({x.first -> left, level + 1});
        }
        if (x.first -> right) {
            q.push({x.first -> right, level + 1});
        }
    }
    for (int i = 1; i < ans.size(); i += 2) {
        reverse(ans[i].begin(), ans[i].end());
    }
    return ans;
}
