/*
A solution to the LeetCode problem "Longest Common Prefix", which, given an array of string, returns the longest common prefix.

*/

char* longestCommonPrefix(char** strs, int strsSize) {
    size_t sizeSmallerString = strlen( strs[ 0 ] );
    int indexSmallerString = 0;

    for    ( int i = 1 ; i < strsSize ; i++)    {
        if    ( sizeSmallerString > strlen( strs[ i ] ) )    {
            sizeSmallerString = strlen( strs[ i ] );
            indexSmallerString = i;
        }
    }

    char* compareSmallerString = ( char* ) malloc ( sizeof (char) * ( sizeSmallerString + 1 ) );

    strcpy( compareSmallerString, strs[ indexSmallerString ] );

    for   ( int i  = 0 ; i < strsSize ; i++)   {
        int j = 0;
        if    ( i != indexSmallerString )    {
            while   ( compareSmallerString[j] != '\0' && compareSmallerString[j] == strs[i][j] )    {
                j++;
            }
        }   else    {
            continue;
        }
        compareSmallerString[j] = '\0';
    }

    return compareSmallerString;
}
