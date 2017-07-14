//Linked List Cycle

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// LGTM
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == NULL || head -> next == NULL) {
            return false;
        }
        ListNode *slow = head -> next;
        ListNode *fast = head -> next -> next;
        while (slow != NULL && fast != NULL && slow != fast) {
            slow = slow -> next;
            if (fast -> next == NULL) {
                return false;
            }
            fast = fast -> next -> next;
        }
        if (slow != NULL && slow == fast) {
            return true;
        }
        return false;
    }
};
