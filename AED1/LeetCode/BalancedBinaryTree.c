/*
A solution to the LeetCode problem "Balance a Binary Tree", which, given the root of a binary tree, returns a balanced binary search binary tree with the same node values.

*/

struct TreeNode* buildBalancedBST( int start, int end, struct TreeNode** array ) {
    if ( start > end )
        return NULL;
    
    int mid = ( end + start ) / 2;

    struct TreeNode* newTree = array[mid];
    newTree->left = buildBalancedBST( start, mid - 1, array );
    newTree->right = buildBalancedBST( mid + 1, end, array );

    return newTree;
}

void insertArray( struct TreeNode* root, int* count, struct TreeNode** array ) {
    if ( root == NULL )
        return;

    insertArray( root->left, count, array );
    array[( *count )++] = root;
    insertArray( root->right, count, array );
}

struct TreeNode* balanceBST(struct TreeNode* root) {
    if ( root == NULL ) 
        return NULL;

    int count = 0;
    struct TreeNode* array[10001];

    insertArray( root, &count, array );

    return buildBalancedBST( 0, count - 1, array );
}
