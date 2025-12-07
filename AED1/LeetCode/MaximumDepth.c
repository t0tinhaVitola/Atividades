/*
A solution to the LeetCode Problem "Maximum Depth of Binary Tree", which, given the root of a binary tree, returns its maximum depth;

*/

int maxDepth(struct TreeNode* root) {
    if ( root == NULL ) {
        return 0;
    }
    int depthL = 1, depthR = 1;
    depthL += maxDepth (root->left); 
    depthR += maxDepth (root->right);
    if ( depthL >= depthR ) {
        return depthL;
    } else {
        return depthR;
    }
}
