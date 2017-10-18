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
        int ret = 0;
        while (l != NULL) {
            l = l -> next;
            ret++;
        }
        return ret;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int n1 = getSize(l1);
        int n2 = getSize(l2);
        if (n1 < n2) {
            return addTwoNumbers(l2, l1);
        }
        ListNode *ret = l1;
        int carry = 0;
        while (l1 != NULL) {
            int add = (l2 != NULL) ? (l2 -> val) : 0;
            l1 -> val = l1 -> val + add + carry;
            carry = (l1 -> val) / 10;
            (l1 -> val) %= 10;
            if (carry && l1 -> next == NULL) {
                l1 -> next = new ListNode(0);
            }
            l1 = l1 -> next;
            if (l2 != NULL) {
                l2 = l2 -> next;
            }
        }
        return ret;
    }
};
