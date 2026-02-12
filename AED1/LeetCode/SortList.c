/*
A solution to the LeetCode problem "Sort List", which, given the had of a linked list, returns the list after sorting it in ascending order.
Time Complexity: O(nLog(n))
Space Complexity: O(Log(n))
*/

struct ListNode* MergeList ( struct ListNode* a, struct ListNode* b ) {
    struct ListNode temp;
    struct ListNode* currentNode = &temp;

    while ( a != NULL && b != NULL ) {
        if ( a->val <= b->val ) {
            currentNode->next = a;
            a = a->next;
        } else {
            currentNode->next = b;
            b = b->next;
        }
        currentNode = currentNode->next;
    }

    if ( a != NULL ) {
        currentNode->next = a;
        a = a->next;
    }

    if ( b != NULL ) {
        currentNode->next = b;
        b = b->next;
    }

    return temp.next;
}

struct ListNode* findMiddle ( struct ListNode* head ) {
    struct ListNode* tempFast = head->next;
    struct ListNode* tempSlow = head;

    while ( tempFast != NULL && tempFast->next != NULL  ) {
        tempSlow = tempSlow->next;
        tempFast = tempFast->next->next;
    }
    
    return tempSlow;
}

struct ListNode* sortList(struct ListNode* head) {
    if ( head == NULL || head->next == NULL )
        return head;
    
    struct ListNode* middle = findMiddle( head );

    struct ListNode* left = head;
    struct ListNode* right = middle->next;
    middle->next = NULL;

    left = sortList( left );
    right = sortList( right );

    struct ListNode* result = MergeList( left, right );
    return result;
}
