/*
A solution to the LeetCode problem "Balanced Binary Tree", which, given the root of a binary tree, returns if its height-balanced.

*/



int verifyBalance(struct TreeNode* root) {
    if ( root == NULL )
        return 0;
    
    int heightL, heightR;

    heightL = verifyBalance( root->left );
    if ( heightL == -1 )
        return -1;

    heightR = verifyBalance( root->right );
    if ( heightR == -1 )
        return -1;
    int result = heightL - heightR;

    if ( result >= -1 && result <= 1 ) {
        if ( heightL >= heightR )
            return heightL + 1;
        return heightR + 1;
    } else {
        return -1;
    }
}
bool isBalanced(struct TreeNode* root) {
    if ( root == NULL )
        return true;

    int result = verifyBalance( root );
    if ( result != -1 ) 
        return true;
    return false;
}
