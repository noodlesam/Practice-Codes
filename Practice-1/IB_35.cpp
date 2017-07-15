/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
void Solution::connect(TreeLinkNode* A) {
    if (A == NULL) {
        return;
    } 
    queue <pair <TreeLinkNode *, int> > q;
    q.push({A, 0});
    int level = -1;
    TreeLinkNode *cur = NULL;
    while (! q.empty()) {
        auto x = q.front();
        q.pop();
        if (x.second != level) {
            level++;
            cur = x.first;
        } else {
            cur -> next = x.first;
            cur = cur -> next;
        }
        if (x.first -> left != NULL) {
            q.push({x.first -> left, x.second + 1});
        }
        if (x.first -> right != NULL) {
            q.push({x.first -> right, x.second + 1});
        }
    }
}
