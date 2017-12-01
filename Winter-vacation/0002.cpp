/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int getSize(ListNode *l) {
        int sz = 0;
        while (l != NULL) {
            l = l -> next;
            sz++;
        }
        return sz;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (getSize(l1) < getSize(l2)) {
            return addTwoNumbers(l2, l1);
        }
        ListNode *ret = l1;
        int carry = 0;
        while (l2 != NULL) {
            (l1 -> val) += (l2 -> val + carry);
            carry = (l1 -> val) / 10;
            (l1 -> val) %= 10;
            if (l1 -> next == NULL && carry) {
                l1 -> next = new ListNode(carry);
                carry = 0;
            }
            l1 = l1 -> next;
            l2 = l2 -> next;
        }
        while (l1 != NULL) {
            (l1 -> val) += carry;
            carry = (l1 -> val) / 10;
            (l1 -> val) %= 10;
            if (l1 -> next == NULL && carry) {
                l1 -> next = new ListNode(carry);
                carry = 0;
            }
            l1 = l1 -> next;
        }
        return ret;
    }
};
