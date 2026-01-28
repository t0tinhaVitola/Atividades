/*
A solution to the LeetCode problem "Lowest Common Ancestor of a Binary Tree", which, given a binary tree, find the lowest common ancestor (LCA) of two given nodes of a tree.

*/


struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    if ( root == NULL || root == p || root == q ) 
        return root;
    
    struct TreeNode* nodeLeft = lowestCommonAncestor( root->left, p, q );
    struct TreeNode* nodeRight = lowestCommonAncestor( root->right, p, q );

    if ( nodeLeft != NULL && nodeRight != NULL )
        return root;
    if ( nodeLeft != NULL ) {
        return nodeLeft;
    } else {
        return nodeRight;
    }
}
