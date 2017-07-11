//Two sum BST

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

TreeNode *get_next(stack <TreeNode *> &s) {
    TreeNode *ret = NULL;
    if (! s.empty()) {
        TreeNode *cur = ret = s.top();
        s.pop();
        if (cur -> right != NULL) {
            cur = cur -> right;
            s.push(cur);
            while (cur -> left != NULL) {
                s.push(cur -> left);
                cur = cur -> left;
            }
        }
    }    
    return ret;
}

TreeNode *get_prev(stack <TreeNode *> &s) {
    TreeNode *ret = NULL;
    if (! s.empty()) {
        TreeNode *cur = ret = s.top();
        s.pop();
        if (cur -> left != NULL) {
            cur = cur -> left;
            s.push(cur);
            while (cur -> right != NULL) {
                s.push(cur -> right);
                cur = cur -> right;
            }
        }
    }
    return ret;
}

int Solution::t2Sum(TreeNode* A, int B) {
    if (A == NULL) {
        return 0;
    }
    stack <TreeNode *> s1;
    stack <TreeNode *> s2;
    TreeNode *cur1 = A;
    TreeNode *cur2 = A;
    while (cur1 != NULL) {
        s1.push(cur1);
        cur1 = cur1 -> left;
    }
    while (cur2 != NULL) {
        s2.push(cur2);
        cur2 = cur2 -> right;
    }
    cur1 = get_next(s1);
    cur2 = get_prev(s2);
    while (cur1 != NULL && cur2 != NULL && cur1 != cur2) {
        int cursum = cur1 -> val + cur2 -> val;
        if (cursum < B) {
            cur1 = get_next(s1);
        } else if (cursum > B) {
            cur2 = get_prev(s2);
        } else {
            return 1;
        }
    }
    return 0;
}
