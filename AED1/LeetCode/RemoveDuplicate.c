/*
A solution to the LeetCode problem "Remove Duplication from Sorted Array".
Description:

"Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. The relative order of the elements should be kept the same.
 Consider the number of unique elements in nums to be k​​​​​​​​​​​​​​. After removing duplicates, return the number of unique elements k. 
 The first k elements of nums should contain the unique numbers in sorted order. The remaining elements beyond index k - 1 can be ignored."

*/
int removeDuplicates(int* nums, int numsSize) {

    if    ( numsSize <= 1 )    {
        return numsSize;
    }

    int temp = 0;
    
    for    ( int i = 1 ; i < numsSize ; i++ )    {
        if    (nums[ temp ] != nums[ i ])    {
            temp++;
            nums[ temp ] = nums[ i ];
        }
    }
    
    return temp + 1;
}
