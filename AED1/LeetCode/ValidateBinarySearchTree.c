/*
A solution to the LeetCode problem, which, given the root of a binary tree, determine if its a valid binary search tree.

*/

#import <math.h>
#import <limits.h>

void checkTree ( struct TreeNode* root, long min, long max, bool* checkNodeP ) {
    if ( *checkNodeP == false )
        return;
    if ( root == NULL ) {
        return;
    }

    if ( root->val <= min || root->val >= max ) {
        *checkNodeP = false;
        return;
    }

    checkTree ( root->left, min, root->val, checkNodeP );
    checkTree ( root->right, root->val, max, checkNodeP );

    return;
}

bool isValidBST(struct TreeNode* root) {
    if ( root == NULL )
        return true;
    
    bool checkNode = true;
    bool* checkNodeP = &checkNode;
    
    checkTree ( root, LONG_MIN, LONG_MAX, checkNodeP );
    if ( checkNode ) {
        return true;
    } else {
        return false;
    }

}
