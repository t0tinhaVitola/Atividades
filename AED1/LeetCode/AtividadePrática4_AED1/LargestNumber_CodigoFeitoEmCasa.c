int whichIsHigher ( const void* n1, const void* n2 ) {
    char a[11], b[11];
    sprintf( a, "%d", *(const int*) n1 );
    sprintf( b, "%d", *(const int*) n2 );

    char temp1[21];
    sprintf(temp1, "%s%s", a, b);
    char temp2[21];
    sprintf(temp2, "%s%s", b, a);

    return strcmp(temp2, temp1);
}

char* largestNumber(int* nums, int numsSize) {
    qsort( nums, numsSize, sizeof(int), whichIsHigher );

    if ( nums[0] == 0 ) {
        char* result = malloc( 2 * sizeof(char) );
        sprintf(result, "%d", 0);
        return result;
    }

    char* result = malloc( ( numsSize * 10 + 1 ) * sizeof(char) );
    int temp = 0;

    for ( int i = 0; i < numsSize; i++ ) {
        temp += sprintf( result + temp, "%d", nums[i] );
    }

    return result;

}
