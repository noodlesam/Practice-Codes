//BST Iterator

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

stack <TreeNode *> s;

BSTIterator::BSTIterator(TreeNode *root) {
    while (! s.empty()) {
        s.pop();
    }
    while (root != NULL) {
        s.push(root);
        root = root -> left;
    }
}

/** @return whether we have a next smallest number */
bool BSTIterator::hasNext() {
    return (! s.empty());
}

/** @return the next smallest number */
int BSTIterator::next() {
    TreeNode *ret = NULL;
    TreeNode *cur = ret = s.top();
    s.pop();
    if (cur -> right != NULL) {
        cur = cur -> right;
        while (cur != NULL) {
            s.push(cur);
            cur = cur -> left;
        }
    }
    return ret -> val;
}

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
