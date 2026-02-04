/*
A solution to the LeetCode problem "Delete Node in a BST", which, given the root of a BST and a key, delete the node with the given key in the BST. Retuns the root node reference of the BST.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* deleteNode(struct TreeNode* root, int key) {
    if ( root == NULL )
        return NULL;

    if ( root->val > key ) {
        root->left = deleteNode( root->left, key );
    } else if ( root->val < key ) {
        root->right = deleteNode( root->right, key );
    } else {
        if ( root->right == NULL && root->left == NULL ) {
            free( root );
            return NULL;
        } else if ( root->right == NULL ) {
            struct TreeNode* temp = root->left;
            free( root );
            return temp;
        } else if ( root->left == NULL ) {
            struct TreeNode* temp = root->right;
            free( root );
            return temp;
        }

        struct TreeNode* temp = root->left;
        while ( temp->right != NULL ) {
            temp = temp->right;
        }

        root->val = temp->val;
        root->left = deleteNode( root->left, temp->val );
    }

    return root;
}
