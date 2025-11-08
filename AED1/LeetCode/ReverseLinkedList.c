/*
A solution to the LeetCode problem "Reverse Linked List", which, given the head of a linked list, reverse the list, then return the reversed list.

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* current = head;
    struct ListNode* nextNode = NULL;
    struct ListNode* previousNode = NULL;

    while    ( current != NULL )    {
        nextNode = current->next;
        current->next = previousNode;
        previousNode = current;
        current = nextNode;
    }

    return previousNode;
}
