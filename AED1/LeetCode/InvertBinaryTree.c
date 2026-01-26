/*
A solution to the LeetCode problem, which, given the root of a binary tree, invert the tree, and return its root.

*/

struct TreeNode* invertTree(struct TreeNode* root) {
    if ( root == NULL ) 
        return NULL;
    
    struct TreeNode* leftRoot = invertTree(root->left);
    struct TreeNode* rightRoot = invertTree(root->right);

    root->right = leftRoot;
    root->left = rightRoot;

    return root;
}
