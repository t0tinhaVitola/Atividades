/*
A solution to the LeetCode problem "Merge Two Sorted Lists", which, given the heads of two sorted lists, the fuction merge the two lists into one sorted list.

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    if    ( list1 == NULL )    {
        return list2;
    }
    if    ( list2 == NULL )    {
        return list1;
    }

    struct ListNode* newList = NULL;

    if    ( list1->val <= list2->val)    {
        newList = list1;
        list1 = list1->next;
    }    else    {
        newList = list2;
        list2 = list2->next;
    }

    struct ListNode* temp = newList;

    while    ( list1 != NULL && list2 != NULL )    {
        if    ( list1->val <= list2->val )    {
            temp->next = list1;
            list1 = list1->next;
        }    else    {
            temp->next = list2;
            list2 = list2->next;
        }
        temp = temp->next;
    }

    if    ( list1 == NULL )    {
        temp->next = list2;
    }    else    {
        temp->next = list1;
    }

    return newList;
}
