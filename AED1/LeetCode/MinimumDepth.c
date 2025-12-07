/*
A solution to the LeetCode problem, which, given the root of a binary tree, finds the shortest path from the root node down to the nearest leaf code.
*/

int minDepth(struct TreeNode* root) {
    if ( root == NULL ) {
        return 0;
    }
    int depthL = 1, depthR = 1;

    depthL += minDepth(root->left);
    depthR += minDepth(root->right);

    if ( root->left == NULL ) {
        return depthR;
    } 
    if ( root->right == NULL ) {
        return depthL;
    }

    if ( depthL <= depthR ) {
        return depthL;
    } else {
        return depthR;
    }
}
