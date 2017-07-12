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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *travA = headA;
        ListNode *travB = headB;
        int lenA = 0;
        int lenB = 0;
        while (travA != NULL) {
            travA = travA -> next;
            lenA++;
        }
        while (travB != NULL) {
            travB = travB -> next;
            lenB++;
        }
        if (lenA < lenB) {
            swap(lenA, lenB);
            swap(headA, headB);
        }
        int diff = lenA - lenB;
        travA = headA;
        travB = headB;
        while (diff-- > 0) {
            travA = travA -> next;
        }
        while (travA != travB) {
            travA = travA -> next;
            travB = travB -> next;
        }
        return travA;
    }
};
