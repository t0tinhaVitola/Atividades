/*
A solution to the LeetCode problem "Binary Tree Level Order Traversal", which, given the root of a binary tree, returns the level order traversal of its node's values.

*/

int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    if ( root == NULL ) {
        *returnSize = 0;
        return NULL;
    }
    
    int** resultList = ( int** ) malloc ( 2000 *sizeof( int* ) );
    *returnColumnSizes = ( int* ) malloc( 2000 * sizeof( int ) );

    struct TreeNode* queue[2000];
    int front = 0, rear = 0;

    queue[rear++] = root;
    *returnSize = 0;

    while ( front < rear ) {
        int nElements = rear - front;
        resultList[*returnSize] = malloc( nElements * sizeof( int ) );
        ( *returnColumnSizes )[*returnSize] = nElements;

        for ( int j = 0; j < nElements; j++ ) {
            struct TreeNode* temp = queue[front++];
            resultList[*returnSize][j] = temp->val;
            
            if ( temp->left != NULL )
                queue[rear++] = temp->left;
            if ( temp->right != NULL )
                queue[rear++] = temp->right;
        }
        (*returnSize)++;    
    }
    return resultList;
}
