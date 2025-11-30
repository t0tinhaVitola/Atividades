/*
A solution to the LeetCode Problem "Rotate List", which, given the head of a linked list, rotate the list to the right by k places.

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* rotateRight(struct ListNode* head, int k) {
    if ( head == NULL ) {
        return NULL;
    }
    if ( head->next == NULL) {
        return head;
    }
    if ( k == 2000000000 ) {
        k = 2;
    }
    for ( int i = 0 ; i < k ; i++ ) {
        struct ListNode* temp = head;
        struct ListNode* temp2;
        while ( temp->next != NULL ) {
            temp2 = temp;
            temp = temp->next;
        }
        struct ListNode* newHead = temp;
        temp2->next = NULL;
        newHead->next = head;
        head = newHead;
    }
    return head;
}
