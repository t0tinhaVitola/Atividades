/*
A solution to the LeetCode problem "Convert Sorted Array to Binary Search Tree", which, given a sorted array, converts it to a height-balanced binary search tree.
*/

void insertSortedArrayToBST( struct TreeNode** root, int* nums , int start, int end ) {
    if ( start > end ) {
        return;
    }
    
    int mid = (start + end) / 2;
    if ( *root == NULL ) {
        *root = malloc( sizeof( struct TreeNode ) );
        (*root)->val = nums[mid];
        (*root)->left = NULL;
        (*root)->right = NULL;
    }
    insertSortedArrayToBST( &( (*root)->left ), nums, start, mid - 1);
    insertSortedArrayToBST( &( (*root)->right ), nums, mid + 1, end);
}
struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {
    struct TreeNode* root = NULL;

    insertSortedArrayToBST( &root, nums, 0, numsSize - 1 );

    return root;
}
