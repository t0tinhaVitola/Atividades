/*
A solution to the LeetCode problem "Implement Queue using Stacks".
Description:
"Implement a first in first out (FIFO) queue using only two stacks. The implemented queue should support all the functions of a normal queue (push, peek, pop, and empty).

Implement the MyQueue class:
- void push(int x): Pushes element x to the back of the queue.
- int pop(): Removes the element from the front of the queue and returns it.
- int peek(): Returns the element at the front of the queue.
- boolean empty(): Returns true if the queue is empty, false otherwise.

Notes:
You must use only standard operations of a stack, which means only push to top, peek/pop from top, size, and is empty operations are valid.
Depending on your language, the stack may not be supported natively. You may simulate a stack using a list or deque (double-ended queue) as long as you use only a stack's standard operations."
*/


typedef struct Node_s{
    int data;
    struct Node_s* next;
} Node_t;

typedef struct {
    Node_t* stack1; 
    Node_t* stack2; 
} MyQueue;


MyQueue* myQueueCreate() {
    MyQueue* st = ( MyQueue* )malloc( sizeof( MyQueue ) );
    if ( st == NULL ) {
        return NULL;
    }
    st->stack1 = NULL;
    st->stack2 = NULL;
    return st;
}

void myQueuePush(MyQueue* obj, int x) {
    Node_t* newNode = ( Node_t* )malloc( sizeof ( Node_t ) );
    if ( newNode == NULL ) {
        return;
    }
    newNode->data = x;
    newNode->next = obj->stack1;
    obj->stack1 = newNode;
    return;
}

int myQueuePop(MyQueue* obj) {
    if ( obj->stack2 == NULL ) {
        while ( obj->stack1 != NULL ) {
            Node_t* temp = obj->stack1;
            obj->stack1 = obj->stack1->next;
            temp->next = obj->stack2;
            obj->stack2 = temp;
        }
    } 
    int pop;
    if ( obj->stack2 != NULL ) {
        Node_t* temp = obj->stack2;
        obj->stack2 = obj->stack2->next;
        pop = temp->data;
        free ( temp );
        return pop;
    }
    return -1;
}

int myQueuePeek(MyQueue* obj) {
    if ( obj->stack2 == NULL ) {
        while ( obj->stack1 != NULL ) {
            Node_t* temp = obj->stack1;
            obj->stack1 = obj->stack1->next;
            temp->next = obj->stack2;
            obj->stack2 = temp;
        }
    }
    if ( obj->stack2 != NULL ) {
        return obj->stack2->data;
    }
    return -1;
}

bool myQueueEmpty(MyQueue* obj) {
    if ( obj->stack1 == NULL && obj->stack2 == NULL) {
        return true;
    } else {
        return false;
    }
}

void myQueueFree(MyQueue* obj) {
    if ( myQueueEmpty( obj ) == true ) {
        return;
    } else {
        Node_t* temp = NULL;
        while ( obj->stack1 != NULL ) {
            temp = obj->stack1;
            obj->stack1 = obj->stack1->next;
            free ( temp );
        }
        while ( obj->stack2 != NULL ) {
            temp = obj->stack2;
            obj->stack2 = obj->stack2->next;
            free ( temp );
        }        
        free ( obj );
    }
}
