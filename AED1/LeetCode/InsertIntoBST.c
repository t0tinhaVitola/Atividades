/*
A solution to the LeetCode problem "Insert into a Binary Search Tree", which, given the root of a BST and a value to insert into the binary tree. 
Returns the root node of the BST after the insertion.
*/

struct TreeNode* insertIntoBST(struct TreeNode* root, int val) {
    if ( root == NULL ) {
        struct TreeNode* newNode = ( struct TreeNode* ) malloc( sizeof( struct TreeNode ) );
        newNode->val = val;
        newNode->right = NULL;
        newNode->left = NULL;
        return newNode;
    }

    if ( val < root->val ) {
        root->left = insertIntoBST( root->left, val );
    } else {
        root->right = insertIntoBST( root->right, val );
    }
    return root;
}
