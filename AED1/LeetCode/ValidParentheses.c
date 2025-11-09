/*
A solution to the LeetCode problem 'Valid Parentheses', which, given a string containing just the characters '(', ')', '[', ']', '{' and '}', 
determines if every close bracket has a corresponding open bracket of the same type.


*/

typedef struct Node_s    {
    char symbol;
    struct Node_s* next;
} Node_t;

typedef struct Stack_s    {
    Node_t* top;
} Stack_t;

void Initialize ( Stack_t* s )    {
    s->top = NULL;
}

void Push ( Stack_t* s, char value )    {
    Node_t* newNode = ( Node_t* )malloc( sizeof( Node_t ) );
    if    ( newNode == NULL )    {
        exit( 1 );
    }
    newNode->symbol = value;
    newNode->next = s->top;
    s->top = newNode;
}

void Pop ( Stack_t* s )    {
    if    ( s->top == NULL )    {
        exit( 1 );
    }
    Node_t* temp = s->top;
    s->top = s->top->next;
    free( temp );
    return;
}
bool isValid( char* s ) {
    Stack_t* st = ( Stack_t* )malloc( sizeof( Stack_t ) );
    if ( st == NULL ) {
        return false;
    }
    Initialize(st);
    for    ( int i = 0; i < strlen(s) ; i++ )    {
        if ( s[i] == '(' || s[i] == '{' || s[i] == '[' )    {
            Push(st, s[i]);
        } else if ( s[i] == ')' || s[i] == ']' || s[i] == '}' )    {
            if ( st->top == NULL ) {
                free(st);
                return false;
            }
            if ( st->top->symbol == '(' && s[i] == ')' || st->top->symbol == '[' && s[i] == ']' || st->top->symbol == '{' && s[i] == '}' )    {
                Pop( st );
            } else {
                free( st );
                return false;
            }
        }
    }
    if ( st->top == NULL ) {
        free( st );
        return true;
    } else {
        free( st );
        return false;
    }
}
