/*
A solution to the LeetCode problem, which, given the root ofo a binary Tree, return in-order traversal of its node's values.
(The number of nodes is in the range [0, 100].)

*/

void traverse( struct TreeNode* root, int* index, int* arrayResult ) {
    if ( root == NULL ) 
        return;

    traverse( root->left, index, arrayResult );
    arrayResult[ ( *index )++ ] = root->val;
    traverse( root->right, index, arrayResult );
}

int* inorderTraversal(struct TreeNode* root, int* returnSize) {

    int* arrayResult = ( int* ) malloc ( 100 * sizeof( int ) );
    *returnSize = 0;

    traverse( root, returnSize, arrayResult ); 

    return arrayResult;
}
