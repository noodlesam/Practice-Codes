//Swap list nodes in pairs

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode *Solution::swapPairs(ListNode *A) {
    ListNode *dummy = new ListNode(0);
    dummy -> next = A;
    ListNode *prev = dummy;
    ListNode *cur = A;
    while (cur != NULL && cur -> next != NULL) {
        prev -> next = cur -> next;
        cur -> next = cur -> next -> next;
        prev -> next -> next = cur;
        prev = prev -> next -> next;
        cur = prev -> next;
    }    
    return dummy -> next;
}
