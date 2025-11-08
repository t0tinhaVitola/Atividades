/*
A solution to the LeetCode problem "Remove Nth Node from End of List", which, given the head of a linked list, remove the "nth" node from the end of the list and returns its head.

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {

    if    ( head->next == NULL )    {
        head = NULL;
        return NULL;
    }

    struct ListNode* fast = head;
    struct ListNode* slow = head;

    for    ( int i = 0 ; i < n ; i++ )    {
        fast = fast->next;
    }

    if    (fast == NULL)    {
        return head->next;
    }
    
    while    ( fast->next != NULL )    {
        fast = fast->next;
        slow = slow->next;
    }

    slow->next = slow->next->next;

    return head;

}
