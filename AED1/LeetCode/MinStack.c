/*
A solution to the LeetCode problem "Min Stack".
Descryption:

"Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

Implement the MinStack class:

- MinStack() initializes the stack object.
- void push(int val) pushes the element val onto the stack.
- void pop() removes the element on the top of the stack.
- int top() gets the top element of the stack.
- int getMin() retrieves the minimum element in the stack.

You must implement a solution with O(1) time complexity for each function."

*/

typedef struct Node_s {
    int number;
    struct Node_s* next;
} Node_t;

typedef struct {
    Node_t* minTop;
    Node_t* top;
} MinStack;


MinStack* minStackCreate( ) {
    MinStack* minSt = ( MinStack* )malloc( sizeof( MinStack ) );
    if ( minSt == NULL ) {
        return NULL;
    }
    minSt->top = NULL;
    minSt->minTop = NULL;
    return minSt;
}

void minStackPush( MinStack* obj, int val ) {
    Node_t* newNode = ( Node_t* )malloc( sizeof( Node_t ) );
    if ( newNode == NULL ) {
        return;
    }
    newNode->number = val;
    newNode->next = obj->top;
    obj->top = newNode;

    if (obj->minTop == NULL || obj->minTop->number >= val ) {
        Node_t* newNode2 = ( Node_t* )malloc( sizeof( Node_t ) );
        if ( newNode2 == NULL ) {
            return;
        }
        newNode2->number = val;
        newNode2->next = obj->minTop;
        obj->minTop = newNode2;
    }
}

void minStackPop( MinStack* obj ) {
    if ( obj->top == NULL ) {
        return;
    }
    Node_t* temp = obj->top;
    obj->top = obj->top->next;

    if ( obj->minTop->number == temp->number ) {
        Node_t* temp2 = obj->minTop;
        obj->minTop = obj->minTop->next;
        free(temp2);
    }

    free(temp);
}

int minStackTop(MinStack* obj) {
    return obj->top->number;
}

int minStackGetMin(MinStack* obj) {
    return obj->minTop->number;
}

void minStackFree(MinStack* obj) {
    Node_t* temp = NULL;
    while ( obj->top != NULL ) {
        temp = obj->top;
        obj->top = obj->top->next;
        free(temp);
    }
    while (obj->minTop != NULL ) {
        temp = obj->minTop;
        obj->minTop = obj->minTop->next;
        free(temp);
    }
    free (obj);
}
