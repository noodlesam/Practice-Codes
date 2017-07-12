//Copy List with Random Pointer

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        unordered_map <RandomListNode *, RandomListNode *> m;
        m[NULL] = NULL;
        RandomListNode *trav = head;
        while (trav != NULL) {
            RandomListNode *temp = new RandomListNode(trav -> label);
            m[trav] = temp;
            trav = trav -> next;
        }
        trav = head;
        while (trav != NULL) {
            m[trav] -> next = m[trav -> next];
            m[trav] -> random = m[trav -> random];
            trav = trav -> next;
        }
        return m[head];
    }
};
