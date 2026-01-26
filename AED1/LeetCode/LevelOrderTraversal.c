/*
A solution to the LeetCode problem "Binary Tree Level Order Traversal", which, given the root of a binary tree, returns the level order traversal of its node's values.

*/

void traverse( struct TreeNode* root, int index, int* returnSize, int** returnColumnSizes, int** resultArray ) {
    if ( root == NULL )
        return;
    if ( index >= *returnSize ) {
        resultArray[index] = ( int* ) malloc ( 2000 * sizeof( int ) );
        ( *returnColumnSizes )[ index ] = 0;
        *returnSize += 1;
    }
    int row = index++;
    int column = ( *returnColumnSizes )[ row ]++;

    resultArray[ row ][ column ] = root->val;

    traverse( root->left, index, returnSize, returnColumnSizes, resultArray );
    traverse( root->right, index, returnSize, returnColumnSizes, resultArray );

}

int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    int** resultArray = ( int** ) malloc ( 2000 * sizeof( int* ) );
    *returnColumnSizes = ( int* ) malloc ( 2000 * sizeof( int ) );
    *returnSize = 0;

    traverse( root, 0, returnSize, returnColumnSizes, resultArray );

    return resultArray;
}
