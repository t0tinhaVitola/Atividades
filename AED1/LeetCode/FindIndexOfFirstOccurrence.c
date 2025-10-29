/*
A solution to the LeetCode Problem "Find the Index of the First Occurrence in a String", which, given two strings, needle and haystack, returns the zero-based index of the first occurrence of the needle. 
The function returns -1 if the needle is not found, and 0 if the needle is an empty string.
*/

int strStr(char* haystack, char* needle) {
    size_t length = strlen( needle );

    if    ( strlen( haystack ) < length ){
        return -1;
    }
    
    int index;

    char* compare = ( char* )malloc( sizeof( char ) * ( length + 1 ) );

    for    ( int i = 0 ; i < strlen( haystack ) - length + 1 ; i++){
        for    ( int j = 0 ; j < length ; j++){
            compare[ j ] = haystack[ j + i ];
        }
        compare[ length ] = '\0';

        if    ( strcmp( needle, compare ) == 0 )    {
            free(compare);
            return i;
        }
    }
    free(compare);
    return -1;
}
