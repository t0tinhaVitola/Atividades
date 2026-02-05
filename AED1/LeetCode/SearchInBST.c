/*
A solution to the LeetCode problem "Search in a Binary Search Tree", which, given the root of a BST and an integer value, returns if there's a node with that value in the BST (or not).
*/

struct TreeNode* search( struct TreeNode* root, int val, struct TreeNode** temp ) {
    if ( root == NULL )
        return NULL;
    
    if ( root->val == val ) {
        *temp = root;
        return NULL;
    }

    if ( val < root->val && *temp == NULL ) {
        search( root->left, val, temp );
    } else if ( val > root->val && *temp == NULL ) {
        search( root->right, val, temp);
    }

    return NULL;
}

struct TreeNode* searchBST(struct TreeNode* root, int val) {
    if ( root == NULL )
        return NULL;
    
    struct TreeNode* temp = NULL;
    search( root, val, &temp );

    return temp;
}
