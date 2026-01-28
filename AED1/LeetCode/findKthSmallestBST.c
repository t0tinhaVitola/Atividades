/*
A solution to the LeetCode problem "Kth Smallest Element in a BST", which, given a root of a BST, and a integer k, returns the k"th" smallest value of all the values of the nodes in the tree.
*/

void findKthSmallest ( struct TreeNode* root, int k, int* desiredNumber, int* counter ) {
    if ( root == NULL )
        return;
    
    findKthSmallest( root->left, k, desiredNumber, counter );
    *counter += 1;

    if ( *counter == k ) {
        *desiredNumber = root->val;
        return;
    }
    
    findKthSmallest( root->right, k, desiredNumber, counter );
    return;

}

int kthSmallest(struct TreeNode* root, int k) {
    if ( root == NULL )
        return 0;
    int desiredNumber = -1;
    int counter = 0;
    findKthSmallest( root, k, &desiredNumber, &counter );
    return desiredNumber;

}
